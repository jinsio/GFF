#pragma once

// インクルード
#include "DxLib.h"

//プレイヤーの初期位置
const int FirstPosX= 0;
const int FirstPosY = 100;

const int CharaIdleAllNum = 2;
const int CharaIdleXNum = 2;
const int CharaIdleYNum = 1;
const int CharaIdleXSize = 64;
const int CharaIdleYSize = 64;


//プレイヤークラス
class Player
{
public:
	//コンストラクタ
	Player();
	//デストラクタ
	~Player();

	/// <summary>
	/// プレイヤーの描画
	/// </summary>
	
	void Draw();
	void Move();
	void IdleAnimation();

	
private:
	int mIdle[CharaIdleAllNum];
	int pImage;
	int mIdleAnimation;
	bool direction;
	float deltaTime;
	VECTOR mPlayer;
	
};