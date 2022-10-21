#pragma once

// インクルード
#include "DxLib.h"

//プレイヤーの初期位置
const int FirstPosX= 0;
const int FirstPosY = 100;

const int IdleAllNum = 2;
const int IdleXNum = 2;
const int IdleYNum = 1;
const int XSize = 64;
const int YSize = 64;


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
	void Init();
	void Draw();
	void Move();
	void IdleAnimation();

private:
	int mIdle[IdleAllNum];
	int pImage;
	int mIdleAnimation;
	bool direction;
	int nowcount, prevCount;
	float deltaTime;
	VECTOR mPlayer;
	
};