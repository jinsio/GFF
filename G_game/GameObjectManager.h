//------------------------------------------------------------------------------
// @brief ゲームオブジェクトマネージャ
//------------------------------------------------------------------------------
#pragma once

#include <vector>
#include <unordered_map>
#include <DxLib.h>

#include "GameObject.h"
#include "GameObjectTag.h"
#include <math.h>

class GameObjectManager final
{
public:
	static void Initialize();                              // ゲームオブジェクトマネージャの初期化処理
	static void Entry(GameObject* newObj);                 // ゲームオブジェクト登録
	static void Release(GameObject* releaseObj);           // ゲームオブジェクト削除
	static void ReleaseAllObj();                           // 全オブジェクト削除


	static void Update(float deltaTime);                   // 全オブジェクトの更新処理
	static void Draw(int offSetX, int offSetY);                                    // 描画

	static GameObject* GetFirstGameObject(GameObjectTag tag);;	//// オブジェクトタグ種の最初のGameObjectを返す

	static void Finalize();

private:
	GameObjectManager();                                   // シングルトン
	~GameObjectManager();                                  // ゲームオブジェクトマネージャデストラクタ
	static GameObjectManager* mpInstance;                  // マネージャの実体（アプリ内に唯一存在)
	std::vector<GameObject*>  mPendingObjects;             // 一時待機オブジェクト
	std::unordered_map<GameObjectTag, std::vector<GameObject*>>  mObjects;                    // mObjects[タグ種類][オブジェクト個数]; 
};

