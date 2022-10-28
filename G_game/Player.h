#pragma once

// インクルード
#include "DxLib.h"

//プレイヤーの初期位置
const int FirstPosX= 100;
const int FirstPosY = 100;

const int XSize = 64;
const int YSize = 64;

const int IdleAllNum = 2;
const int IdleXNum = 2;
const int IdleYNum = 1;

const int RunAllNum = 8;
const int RunXNum = 8;
const int RunYNum = 1;

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
	void SetdeltaTime();
	float GetdeltaTime() {return deltaTime; }
	void Move();

	void IdleAnimation();
	void IdleDraw();

	void RunAnimation();
	void RunDraw();

	void AllDraw();
	VECTOR& GetPosition() { return mPlayer; }

private:
	bool IsRightDir;
	VECTOR mPlayer;
	
	float nowCount, prevCount;
	float deltaTime;

	int mIdle[IdleAllNum];
	int mIdleAnimation;
	float mIdleAnimCoolTime;


	int mRun[RunAllNum];
	int mRunAnimation;
	float mRunAnimCoolTime;
	
	
};