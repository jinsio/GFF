// インクルード
#include "Dxlib.h"
#include "PlayScene.h"
#include "Player.h"
#include "Collision.h"

Player::Player():
	mPlayer(),
	mIdle{},
	mIdleAnimation(0),
	mIdleAnimCoolTime(1.0f),
	mRun{},
	mRunAnimation(0),
	mRunAnimCoolTime(0.2f),
	deltaTime(0.0f),
	nowCount(0.0f),
	prevCount(0.0f),
	IsRightDir(TRUE),
	playerVY(0.0f),
	jumpFlag(false),
	jumpButtonCount(0)
{


	//プレイヤーの初期位置の代入
	mPlayer.x = FirstPosX;
	mPlayer.y = FirstPosY;

	//プレイヤー画像の読み込み
	LoadDivGraph("assets/player/idle.png", IdleAllNum, IdleXNum, IdleYNum, XSize, YSize, mIdle);
	LoadDivGraph("assets/player/player_anim.png", RunAllNum, RunXNum, RunYNum, XSize, YSize, mRun);
}

Player::~Player()
{
}


void Player::SetdeltaTime()
{	
	nowCount = (float)GetNowCount();
	deltaTime = (nowCount - prevCount) / 1000.0f;
	prevCount = nowCount;
}

void Player::AllDraw()
{
	
	//IdleDraw();
	RunDraw();
}

void Player::Move(bool isStand)
{

	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		IsRightDir = FALSE;
		mPlayer.x += 1;
	}
	else if (CheckHitKey(KEY_INPUT_LEFT)) {
		IsRightDir = TRUE;
		mPlayer.x -= 1;
	}
	else if (CheckHitKey(KEY_INPUT_UP)) {
		mPlayer.y -= 5;
	}

	

	jumpFlag = isStand;
	if (CheckHitKey(KEY_INPUT_J) && jumpFlag)
	{

		playerVY = -jumpPower;
	}
	if (!jumpFlag)
	{
		playerVY += gravity;
		if (playerVY > maxFallSpeed)
		{
			playerVY = maxFallSpeed;
		}
	}
	mPlayer.y += playerVY;

}

void Player::IdleAnimation()
{

	mIdleAnimCoolTime -= GetdeltaTime();
	if (mIdleAnimCoolTime < 0.0f) {
		mIdleAnimation++;
		if (mIdleAnimation >= IdleAllNum) {
			mIdleAnimation = 0;
		}
		mIdleAnimCoolTime = 1.0f;
		mIdleAnimation %= IdleAllNum;
	}	
}

void Player::IdleDraw()
{
	IdleAnimation();
	DrawRotaGraph((int)mPlayer.x, (int)mPlayer.y, 1, 0, mIdle[mIdleAnimation], TRUE, IsRightDir);
}

void Player::RunAnimation()
{
	mRunAnimCoolTime -= GetdeltaTime();
	if (mRunAnimCoolTime <= 0.0f) {
		mRunAnimation++;
		if (mRunAnimation >= RunAllNum) {
			mRunAnimation = 0;
		}
		mRunAnimCoolTime = 0.3f;
		mRunAnimation %= RunAllNum;
	}
}

void Player::RunDraw()
{
	RunAnimation();
	DrawRotaGraph((int)mPlayer.x, (int)mPlayer.y, 1, 0, mRun[mRunAnimation], TRUE, IsRightDir);
}
