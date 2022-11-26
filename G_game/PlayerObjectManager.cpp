#include "PlayerObjectManager.h"
#include "PlayerObject.h"

namespace My3dApp
{
	// GameObjectManager実体へのポインタ定義
	GameObjectManager* GameObjectManager::mpInstance = nullptr;

	//------------------------------------------------------------------------------
	// @brief ゲームオブジェクトマネージャ　コンストラクタ
	//------------------------------------------------------------------------------
	GameObjectManager::GameObjectManager()
		: mObjects()
	{
		mpInstance = nullptr;
	}
	//------------------------------------------------------------------------------
	// @brief ゲームオブジェクトマネージャ　デストラクタ
	//------------------------------------------------------------------------------
	GameObjectManager::~GameObjectManager()
	{
		ReleaseAllObj();
	}

	//------------------------------------------------------------------------------
	// @brief ゲームオブジェクトマネージャの初期化関数
	// ゲームオブジェクトマネージャを初期化する。この関数以降、ほかの関数が
	// 使用できるようになる。そのため他の関数使用前にCreateを呼び出す必要がある。
	//------------------------------------------------------------------------------
	void GameObjectManager::Initialize()
	{
		if (!mpInstance)
		{
			mpInstance = new GameObjectManager;
		}
	}

	//------------------------------------------------------------------------------
	// @brief GameObject をGameObjectマネージャに追加
	// @param[in] newObj 新規作成ゲームオブジェクト
	// @detail 新規ゲームオブジェクトをマネージャーに追加する。内部で一時保管された後、
	// Update()内でタグ種類毎に分類され管理される。
	//------------------------------------------------------------------------------
	void GameObjectManager::Entry(PlayerObject* newObj)
	{
		// ペンディングオブジェクトに一時保存
		mpInstance->mPendingObjects.emplace_back(newObj);
	}

	//------------------------------------------------------------------------------
	// @brief GameObject をマネージャから削除
	// @param[in] releaseObj 削除したいオブジェクトのポインタ
	// @detail 削除したいオブジェクトのポインタをマネージャ内で検索し削除する
	//------------------------------------------------------------------------------
	void GameObjectManager::Release(PlayerObject* releaseObj)
	{
		// ペンディングオブジェクト内から検索
		auto iter = std::find(mpInstance->mPendingObjects.begin(),
			mpInstance->mPendingObjects.end(), releaseObj);
		if (iter != mpInstance->mPendingObjects.end())
		{
			// 見つけたオブジェクトを最後尾に移動してデータを消す
			std::iter_swap(iter, mpInstance->mPendingObjects.end() - 1);
			mpInstance->mPendingObjects.pop_back();

			return;
		}

		// アクティブオブジェクト内から削除Objectを検索
		iter = std::find(mpInstance->mObjects.begin(),
			mpInstance->mObjects.end(), releaseObj);
		if (iter != mpInstance->mObjects.end())
		{
			// 見つけたオブジェクトを末尾に移動し、削除
			std::iter_swap(iter, mpInstance->mObjects.end() - 1);
			delete mpInstance->mObjects.back();
		}
	}

	//-------------------------------------------------------------------------------
	// @brief 全オブジェクト削除.
	//-------------------------------------------------------------------------------
	void GameObjectManager::ReleaseAllObj()
	{
		// 末尾からペンディングオブジェクトをすべてを削除
		while (!mpInstance->mPendingObjects.empty())
		{
			delete mpInstance->mPendingObjects.back();
		}

		// 末尾から削除
		while (!mpInstance->mObjects.empty())
		{
			delete mpInstance->mObjects.back();
			mpInstance->mObjects.pop_back();
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
	void GameObjectManager::Update(float deltaTime)
	{
		// すべてのアクターの更新
		// 該当タグにあるすべてのオブジェクトを更新
		for (int i = 0; i < mpInstance->mObjects.size(); ++i)
		{
			mpInstance->mObjects[i]->Update(deltaTime);
		}

		// ペンディング中のオブジェクトをアクティブリストに追加
		for (auto pending : mpInstance->mPendingObjects)
		{
			mpInstance->mObjects.emplace_back(pending);
		}

		mpInstance->mPendingObjects.clear();

		// すべてのアクター中で死んでいるアクターをdeadObjectへ一時保管
		std::vector<PlayerObject*> deadObjects;
		// 死亡Objectを検索し、deadObjectsへ
		for (int i = 0; i < mpInstance->mObjects.size(); ++i)
		{
			// 生きていなかったらdeadObjectへ移動
			if (!mpInstance->mObjects[i]->GetAlive())
			{
				deadObjects.emplace_back(mpInstance->mObjects[i]);
			}
		}

		// 死んでいるオブジェクトをdelete
		for (auto deadObj : deadObjects)
		{
			delete deadObj;
		}
		deadObjects.clear();
	}

	//-------------------------------------------------------------------------------
	// @brief 全オブジェクトの描画処理.
	//-------------------------------------------------------------------------------
	void GameObjectManager::Draw()
	{
		for (int i = 0; i < mpInstance->mObjects.size(); ++i)
		{
			mpInstance->mObjects[i]->Draw();
		}
	}

	//-------------------------------------------------------------------------------
	// @brief  GameObjectManagerの後始末処理.
	// @detail アプリケーション終了前に呼び出す必要がある。マネージャが確保した領域と
	// マネージャ自身の解放処理を行う。Endを行わずに終了した場合はメモリリークを起こす。
	// また、この関数以降はすべてのGameObjectManagerの関数は使用することはできない。
	//-------------------------------------------------------------------------------
	void GameObjectManager::Finalize()
	{
		ReleaseAllObj();
		if (mpInstance)
		{
			delete mpInstance;
			mpInstance = nullptr;
		}
	}

}// namespace My3dApp
