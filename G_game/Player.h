#pragma once

// インクルード
#include "DxLib.h"

//プレイヤーの初期位置
const int FirstPosX= 100;
const int FirstPosY = 100;

//重力
const int Gravity = 1;

//プレイヤーのサイズ
const int XSize = 64;
const int YSize = 64;

//待機アニメーション
const int IdleAllNum = 2;
const int IdleXNum = 2;
const int IdleYNum = 1;

//走りアニメーション
const int RunAllNum = 8;
const int RunXNum = 8;
const int RunYNum = 1;

//投げるアニメーション
const int ThrowAllNum = 6;
const int ThrowXNum = 6;
const int ThrowYNum = 1;

//プレイヤークラス
class Player
{
public:
	//コンストラクタ
	Player();
	//デストラクタ
	~Player();

	/// <summary>
	/// 初期化
	/// </summary>
	void Init();

	/// <summary>
	/// deltaTimeのセッター
	/// </summary>
	void SetdeltaTime();

	/// <summary>
	/// deltaTimeのゲッター
	/// </summary>
	/// <returns>deltaTime</returns>
	float GetdeltaTime() {return deltaTime; }

	/// <summary>
	/// キャラの座標
	/// </summary>
	void Move();
	VECTOR& GetPosition() { return mPlayer; }


	/// <summary>
	/// 待機アニメーション
	/// </summary>
	void IdleAnimation();

	/// <summary>
	/// 待機アニメーション描画
	/// </summary>
	void IdleDraw();
	
	/// <summary>
	/// 走りアニメーション関連
	/// </summary>
	void RunAnimation();
	void RunDraw();

	/// <summary>
	/// キャラのアニメーションの
	/// </summary>
	void CharaAnimation();
	

private:
	//右向きか
	bool IsRightDir;
	
	//Player
	VECTOR mPlayer;
	
	//デルタタイム関連
	float nowCount, prevCount;
	float deltaTime;

	//待機アニメーション関連
	int mIdle[IdleAllNum];
	int mIdleAnimation;
	float mIdleAnimCoolTime;

	//走りアニメ―ション関連
	int mRun[RunAllNum];
	int mRunAnimation;
	float mRunAnimCoolTime;

	//投げアニメーション関連
	int mThrow[ThrowAllNum];
	int mThrowAnimation;
	float mThrowAnimCoolTime;

	
};