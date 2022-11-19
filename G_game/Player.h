#pragma once

// インクルード
#include "DxLib.h"
#include <vector>


//プレイヤーの初期位置
const int FirstPosX= 100;
const int FirstPosY = 100;

//移動速度
const float RunSpeed = 4.0f;

//ジャンプ関連
const float jumpPower = 10.0f;     // ジャンプ初速度
const float gravity = 0.3f;    // 重力
const float maxFallSpeed = 8.0f;   // 最大落下速度


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

//走りアニメーション
const int JumpAllNum = 8;
const int JumpXNum = 8;
const int JumpYNum = 1;

//投げるアニメーション
const int ThrowAllNum = 8;
const int ThrowXNum = 8;
const int ThrowYNum = 1;

//プレイヤークラス
class Player
{
public:
	//コンストラクタ
	Player();
	//デストラクタ
	~Player();

	// 初期化
	void Init();

	//アップデート
	void Update(float _deltaTime,bool isStand);
	
	// deltaTimeのセッター
	void SetdeltaTime();

	// deltaTimeのゲッター
	// <returns>deltaTime
	float GetdeltaTime() {return deltaTime; }

	//キャラの移動
	void Move(bool isStand);

	// キャラの座標
	VECTOR& GetPosition() { return mPlayer; }

	// 待機アニメーション設定
	void IdleAnimation(float _deltaTime);

	// 走りアニメーション設定
	void RunAnimation(float _deltaTime);

	// 投げアニメーション設定
	void ThrowAnimation(float _deltaTime);

	//ジャンプアニメーション設定
	void JumpAnimation(float _deltaTime);

	// アニメーション制御
	void AnimationUpdate(float _deltaTime);

	//描画制御
	void AnimationControl();

	// アニメーション描画
	void Draw();

private:
	//右向きか
	bool IsRightDir;
	
	//Player
	VECTOR mPlayer;
	
	float playerVY;
	bool onGround;
	int jumpButtonCount;


	//デルタタイム関連
	float nowCount, prevCount;
	float deltaTime;

	//アニメーション
	int mHandle;
	int mAnimation;

	//待機アニメーション関連
	int mIdle[IdleAllNum];
	int mIdleAnimation;
	float mIdleAnimCoolTime;

	//走りアニメ―ション関連
	int mRun[RunAllNum];
	int mRunAnimation;
	float mRunAnimCoolTime;

	//ジャンプアニメ―ション関連
	int mJump[JumpAllNum];
	int mJumpAnimation;
	float mJumpAnimCoolTime;
	bool jumpFlag;

	//投げアニメーション関連
	int mThrow[ThrowAllNum];
	int mThrowAnimation;
	float mThrowAnimCoolTime;

};