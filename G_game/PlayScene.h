#pragma once

// インクルード
#include "SceneBase.h"

class Map;
class Collision;
class Player;
class Bullet;

/* プレイシーン */
class PlayScene :public SceneBase
{
private:
	Map* map;
	Collision* collision;
	Player* player;
	Bullet* bullet;
public:
	// コンストラクタ
	PlayScene();
	// デストラクタ
	~PlayScene();

	/// <summary>
	/// シーンの更新処理
	/// </summary>
	/// <returns>現在のシーンのポインタ</returns>
	SceneBase* Update(float _deltaTime)override;

	/// <summary>
	/// シーンとキャラの描画
	/// </summary>
	void Draw()override;
};

