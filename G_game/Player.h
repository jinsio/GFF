#pragma once

// インクルード
#include "DxLib.h"
#include <vector>
#include "PlayerObject.h"

//プレイヤーの初期位置
const int FirstPosX= 400;
const int FirstPosY = 200;

//移動速度
const float RunSpeed = 250.0f;

//ジャンプ関連
const float jumpPower = 12.0f;     // ジャンプ初速度
const float gravity = 0.3f;    // 重力
const float maxFallSpeed = 10.0f;   // 最大落下速度


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

//ジャンプアニメーション
const int JumpAllNum = 8;
const int JumpXNum = 8;
const int JumpYNum = 1;

//投げるアニメーション
const int ThrowAllNum = 8;
const int ThrowXNum = 8;
const int ThrowYNum = 1;

//プレイヤークラス
class Player:public PlayerObject
{
public:
	//コンストラクタ
	Player();
	//デストラクタ
	~Player();

	// 初期化
	void Init();

	//アップデート
	void Update(float deltaTime) override;

	// deltaTimeのゲッター
	// <returns>deltaTime
	float GetdeltaTime() {return deltaTime; }

	//キャラが立っているか
	void SetonGround(bool isStand) { onGround=isStand; }

	//キャラの移動
	void Move(float deltaTime);

	// キャラの座標
	VECTOR& GetPosition() { return mPos; }

	//キャラの重力
	float GetVY() { return playerVY; }

	//キャラの向き
	int GetDir() { return mRightDir; }


	// 待機アニメーション設定
	void IdleAnimation(float _deltaTime);

	// 走りアニメーション設定
	void RunAnimation(float _deltaTime);

	// 投げアニメーション設定
	void ThrowAnimation(float _deltaTime);

	//ジャンプアニメーション設定
	void JumpAnimation(float deltaTime);

	// アニメーション制御
	void AnimationUpdate(float deltaTime);
	//描画制御
	void AnimationControl();
	// アニメーション描画
	void Draw(int offSetX, int offSetY)override;

private:
	float playerVY;
	bool onGround;
	int jumpButtonCount;

	bool input;

	//デルタタイム関連
	float nowCount, prevCount;
	float deltaTime;

	//アニメーション
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