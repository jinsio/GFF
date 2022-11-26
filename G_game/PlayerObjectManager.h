//------------------------------------------------------------------------------
// @brief ゲームオブジェクトマネージャ
//------------------------------------------------------------------------------
#pragma once

#include <vector>
#include <unordered_map>
#include <DxLib.h>

#include "PlayerObject.h"
#include <math.h>

namespace My3dApp
{
	class GameObjectManager final
	{
	public:
		static void Initialize();                              // ゲームオブジェクトマネージャの初期化処理
		static void Entry(PlayerObject* newObj);                 // ゲームオブジェクト登録
		static void Release(PlayerObject* releaseObj);           // ゲームオブジェクト削除
		static void ReleaseAllObj();                           // 全オブジェクト削除

		static void Update(float deltaTime);                   // 全オブジェクトの更新処理
		static void Draw();                                    // 描画 

		static void Finalize();

	private:
		GameObjectManager();                                   // シングルトン
		~GameObjectManager();                                  // ゲームオブジェクトマネージャデストラクタ
		static GameObjectManager* mpInstance;                  // マネージャの実体（アプリ内に唯一存在)
		std::vector<PlayerObject*>  mPendingObjects;             // 一時待機オブジェクト
		std::vector<PlayerObject*>  mObjects;                    // mObjects[タグ種類][オブジェクト個数]; 
	};

}// namespace My3dApp
