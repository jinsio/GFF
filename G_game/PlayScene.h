#pragma once

// インクルード
#include "SceneBase.h"
#include "PlayerObjectManager.h"
class Map;
class Collision;
class Scroll;
class Player;
class Bullet;
class Button;

/* プレイシーン */
class PlayScene :public SceneBase
{
private:
	
	Map* map;
	Collision* collision;
	Scroll* scroll;
	Player* player;
	Button* button;

	int tmpRadian;
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
	/// キャラが地面に立っているかどうか調べる
	/// </summary>
	void isStand();
	/// <summary>
	/// キャラがバレットを投げるまでの流れ
	/// </summary>
	void ShotFlow();
	/// <summary>
	/// シーンとキャラの描画
	/// </summary>
	void Draw()override;
};

