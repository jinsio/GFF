#include "PlayerObjectManager.h"
#include "PlayerObject.h"


	// GameObjectManager実体へのポインタ定義
	PlayerObjectManager* PlayerObjectManager::mpInstance = nullptr;

	//------------------------------------------------------------------------------
	// @brief ゲームオブジェクトマネージャ　コンストラクタ
	//------------------------------------------------------------------------------
	PlayerObjectManager::PlayerObjectManager()
		: mObjects()
	{
		mpInstance = nullptr;
	}
	//------------------------------------------------------------------------------
	// @brief ゲームオブジェクトマネージャ　デストラクタ
	//------------------------------------------------------------------------------
	PlayerObjectManager::~PlayerObjectManager()
	{
		ReleaseAllObj();
	}

	//------------------------------------------------------------------------------
	// @brief ゲームオブジェクトマネージャの初期化関数
	// ゲームオブジェクトマネージャを初期化する。この関数以降、ほかの関数が
	// 使用できるようになる。そのため他の関数使用前にCreateを呼び出す必要がある。
	//------------------------------------------------------------------------------
	void PlayerObjectManager::Initialize()
	{
		if (!mpInstance)
		{
			mpInstance = new PlayerObjectManager;
		}
	}

	//------------------------------------------------------------------------------
	// @brief GameObject をGameObjectマネージャに追加
	// @param[in] newObj 新規作成ゲームオブジェクト
	// @detail 新規ゲームオブジェクトをマネージャーに追加する。内部で一時保管された後、
	// Update()内でタグ種類毎に分類され管理される。
	//------------------------------------------------------------------------------
	void PlayerObjectManager::Entry(PlayerObject* newObj)
	{
		// ペンディングオブジェクトに一時保存
		mpInstance->mPendingObjects.push_back(newObj);
	}

	//------------------------------------------------------------------------------
	// @brief GameObject をマネージャから削除
	// @param[in] releaseObj 削除したいオブジェクトのポインタ
	// @detail 削除したいオブジェクトのポインタをマネージャ内で検索し削除する
	//------------------------------------------------------------------------------
	void PlayerObjectManager::Release(PlayerObject* releaseObj)
	{
		// ペンディングオブジェクト内から検索
		auto iter = std::find(mpInstance->mPendingObjects.begin(), mpInstance->mPendingObjects.end(), releaseObj);
		if (iter != mpInstance->mPendingObjects.end())
		{
			// 見つけたオブジェクトを最後尾に移動してデータを消す
			std::iter_swap(iter, mpInstance->mPendingObjects.end() - 1);
			mpInstance->mPendingObjects.pop_back();

			return;
		}

		// 解放オブジェクトのタグ種類を得る
		PlayerObjectTag tag = releaseObj->GetTag();

		// アクティブオブジェクト内から削除Objectを検索
		iter = std::find(mpInstance->mObjects[tag].begin(), mpInstance->mObjects[tag].end(), releaseObj);
		if (iter != mpInstance->mObjects[tag].end())
		{
			// 見つけたオブジェクトを末尾に移動し、削除
			std::iter_swap(iter, mpInstance->mObjects[tag].end() - 1);
			delete mpInstance->mObjects[tag].back();
		}
	}

	//-------------------------------------------------------------------------------
	// @brief 全オブジェクト削除.
	//-------------------------------------------------------------------------------
	void PlayerObjectManager::ReleaseAllObj()
	{
		// 末尾からペンディングオブジェクトをすべてを削除
		while (!mpInstance->mPendingObjects.empty())
		{
			delete mpInstance->mPendingObjects.back();
		}

		// すべてのアクティブオブジェクトを削除
		for (auto& tag : ObjectTagAll)
		{
			// 末尾から削除
			while (!mpInstance->mObjects[tag].empty())
			{
				delete mpInstance->mObjects[tag].back();
				mpInstance->mObjects[tag].pop_back();
			}
		}
	}

	//-------------------------------------------------------------------------------
  // @brief 全オブジェクトの更新処理.
  // @param[in] 1フレームの更新時間.
  //
  // @detail 全オブジェクトのUpdateメソッドを呼んだあと、
  // 新規Objectをアクティブリストに追加
  // 死亡Objectをアクティブリストから削除
  //-------------------------------------------------------------------------------
	void PlayerObjectManager::Update(float deltaTime)
	{
		// すべてのアクターの更新
		for (auto& tag : ObjectTagAll)
		{
			// 該当タグにあるすべてのオブジェクトを更新
			for (int i = 0; i < mpInstance->mObjects[tag].size(); ++i)
			{
				mpInstance->mObjects[tag][i]->Update(deltaTime);
			}
		}

		// ペンディング中のオブジェクトをアクティブリストに追加
		for (auto pending : mpInstance->mPendingObjects)
		{
			PlayerObjectTag tag = pending->GetTag();
			mpInstance->mObjects[tag].emplace_back(pending);
		}
		mpInstance->mPendingObjects.clear();

		// 死んでいるObjectをdeadObjectへ一時保管したあと、
		 // vectorから排除
		std::vector<PlayerObject*> deadObjects;
		for (auto& tag : ObjectTagAll)
		{
			// deadObjectへ移動
			for (auto obj : mpInstance->mObjects[tag])
			{
				if (!obj->GetAlive())
				{
					deadObjects.emplace_back(obj);
				}
			}
			// mObjects[tag]から死んでいるオブジェクトのみvectorから除外のみ行う
			// まだGameObjectのdeleteは行わない
			// vector中のremove_ifの使い方については下記URL参考
			// https://programming-place.net/ppp/contents/cpp2/main/remove_element.html#remove_if
			mpInstance->mObjects[tag].erase(std::remove_if(std::begin(mpInstance->mObjects[tag]), std::end(mpInstance->mObjects[tag]), [](PlayerObject* g) { return !g->GetAlive(); }), std::cend(mpInstance->mObjects[tag]));
		}

		// 死んでいるGameObjectをここでdelete
		while (!deadObjects.empty())
		{
			delete deadObjects.back();
			deadObjects.pop_back();
		}
	}

	
	//-------------------------------------------------------------------------------
	// @brief 全オブジェクトの描画処理.
	//-------------------------------------------------------------------------------
	void PlayerObjectManager::Draw(int offSetX,int offSetY)
	{
		for (auto& tag : ObjectTagAll)
		{
			for (int i = 0; i < mpInstance->mObjects[tag].size(); ++i)
			{
				// 描画可能なオブジェクトのみ描画
				if (mpInstance->mObjects[tag][i]->GetVisible())
				{
					mpInstance->mObjects[tag][i]->Draw(offSetX,offSetY);
				}
			}
		}
	}

	////-------------------------------------------------------------------------------
	//// @brief 全オブジェクトの当たり判定.
	////-------------------------------------------------------------------------------
	//void PlayerObjectManager::Collision()
	//{
	//	//////////////////////////////////////
	//	// 当たり判定組み合わせをここに書く
	//	//////////////////////////////////////
	//	// player vs BackGround すべての組み合わせチェック
	//	for (int playernum = 0; playernum < mpInstance->mObjects[ObjectTag::Player].size(); ++playernum)
	//	{
	//		for (int bgnum = 0; bgnum < mpInstance->mObjects[ObjectTag::BackGround].size(); ++bgnum)
	//		{
	//			mpInstance->mObjects[ObjectTag::Player][playernum]->
	//				OnCollisonEnter(mpInstance->mObjects[ObjectTag::BackGround][bgnum]);
	//		}
	//	}
	//}
	//-------------------------------------------------------------------------------
	// @brief タグ種類の初めのオブジェクトを返す.
	// @param[in] tag ObjectTag種類
	//-------------------------------------------------------------------------------
	PlayerObject* PlayerObjectManager::GetFirstGameObject(PlayerObjectTag tag)
	{
		if (mpInstance->mObjects[tag].size() == 0)
		{
			return nullptr;
		}
		return mpInstance->mObjects[tag][0];
	}

	//-------------------------------------------------------------------------------
	// @brief  GameObjectManagerの後始末処理.
	// @detail アプリケーション終了前に呼び出す必要がある。マネージャが確保した領域と
	// マネージャ自身の解放処理を行う。Endを行わずに終了した場合はメモリリークを起こす。
	// また、この関数以降はすべてのGameObjectManagerの関数は使用することはできない。
	//-------------------------------------------------------------------------------
	void PlayerObjectManager::Finalize()
	{
		ReleaseAllObj();
		if (mpInstance)
		{
			delete mpInstance;
			mpInstance = nullptr;
		}
	}