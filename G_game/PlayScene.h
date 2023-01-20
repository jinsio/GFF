#pragma once

// インクルード
#include "SceneBase.h"
#include "PlayerObjectManager.h"

class BackGround;
class Map;
class Collision;
class Scroll;
class SkeltonBlock;

class Player;
class Bullet;
class BulletNumber;
class ShotDummy;
/* プレイシーン */
class PlayScene :public SceneBase
{
private:
	BackGround* bg;
	Map* map;
	Collision* collision;
	Scroll* scroll;
	SkeltonBlock* block;
	
	Player* player;
	ShotDummy* dummy;
	Bullet* bullet;
	BulletNumber* bulletnumber;

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
	void ShotFlow(float _deltaTime);
	/// <summary>
	/// シーンとキャラの描画
	/// </summary>
	void Draw()override;
};

