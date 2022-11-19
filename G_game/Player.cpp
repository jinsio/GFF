// インクルード
#include "Dxlib.h"
#include "PlayScene.h"
#include "Player.h"

Player::Player():
	mPlayer(),
	mHandle{0},
	playerVY(),
	jumpFlag(false),
	onGround(false),
	jumpButtonCount(),
	mAnimation(),
	mIdle{},
	mIdleAnimation(0),
	mIdleAnimCoolTime(1.0f),
	mRun{},
	mRunAnimation(0),
	mRunAnimCoolTime(0.2f),
	mJump{},
	mJumpAnimation(0),
	mJumpAnimCoolTime(0.2f),
	mThrow{},
	mThrowAnimation(),
	mThrowAnimCoolTime(0.2f),
	deltaTime(0.0f),
	nowCount(0.0f),
	prevCount(0.0f),
	IsRightDir(TRUE)
{
	//プレイヤーの初期位置の代入
	mPlayer.x = FirstPosX;
	mPlayer.y = FirstPosY;

}

Player::~Player()
{
}

void Player::Init()
{
	//プレイヤーの初期位置の代入
	mPlayer.x = FirstPosX;
	mPlayer.y = FirstPosY;
	//プレイヤー画像の読み込み
	LoadDivGraph("assets/player/idle.png", IdleAllNum, IdleXNum, IdleYNum, XSize, YSize, mIdle);
	LoadDivGraph("assets/player/player_anim.png", RunAllNum, RunXNum, RunYNum, XSize, YSize, mRun);
	LoadDivGraph("assets/player/Throw.png", ThrowAllNum, ThrowXNum, ThrowYNum, XSize, YSize, mThrow);
	LoadDivGraph("assets/player/Jump.png", JumpAllNum, JumpXNum, JumpYNum, XSize, YSize, mJump);
}

void Player::Update(float _deltaTime,bool isStand)
{
	Move(isStand);
	AnimationUpdate(_deltaTime, isStand);
}

void Player::SetdeltaTime()
{	
	nowCount = (float)GetNowCount();
	deltaTime = (nowCount - prevCount) / 1000.0f;
	prevCount = nowCount;
}

void Player::AnimationUpdate(float _deltaTime, bool isStand)
{
	IdleAnimation(_deltaTime);
	RunAnimation(_deltaTime);
	ThrowAnimation(_deltaTime);
	JumpAnimation(_deltaTime, isStand);
	AnimationControl(isStand);
}




void Player::Move(bool isStand)
{
	if (CheckHitKey(KEY_INPUT_RIGHT)){
		IsRightDir = FALSE;
		mPlayer.x += RunSpeed;
	}
	else if (CheckHitKey(KEY_INPUT_LEFT)) {
		IsRightDir = TRUE;
		mPlayer.x -= RunSpeed;
	}

	onGround = isStand;
	
	if (CheckHitKey(KEY_INPUT_J) && onGround)
	{
		jumpFlag = true;
		if (jumpFlag)
		{
			playerVY = -jumpPower;
			jumpFlag = false;
		}
	}
	if (!jumpFlag&&!onGround)
	{
		playerVY += gravity;
		if (playerVY > maxFallSpeed)
		{
			playerVY = maxFallSpeed;
		}
	}
			mPlayer.y += playerVY;

}



void Player::IdleAnimation(float _deltaTime)
{

	mIdleAnimCoolTime -= _deltaTime;
	if (mIdleAnimCoolTime < 0.0f) {
		mIdleAnimation++;
		if (mIdleAnimation >= IdleAllNum) {
			mIdleAnimation = 0;
		}
		mIdleAnimCoolTime = 1000.0f;
		mIdleAnimation %= IdleAllNum;
	}	
}


void Player::RunAnimation(float _deltaTime)
{
	mRunAnimCoolTime -= _deltaTime;
	if (mRunAnimCoolTime <= 0.0f) {
		mRunAnimation++;
		if (mRunAnimation >= RunAllNum) {
			mRunAnimation = 0;
		}
		mRunAnimCoolTime = 300.0f;
		mRunAnimation %= RunAllNum;
	}
}

void Player::JumpAnimation(float _deltaTime, bool isStand)
{
	onGround = isStand;
	if (!onGround)
	{
		mJumpAnimCoolTime -= _deltaTime;
		if (mJumpAnimCoolTime <= 0.0f) {
			mJumpAnimation++;
			if (mJumpAnimation >= JumpAllNum) {
				mJumpAnimation = 0;
			}
			mJumpAnimCoolTime = 100.0f;
			mJumpAnimation %= JumpAllNum;
		}
	}
	if (onGround)
	{
		mJumpAnimation = 0;
	}
}

void Player::ThrowAnimation(float _deltaTime)
{
	mThrowAnimCoolTime -= _deltaTime;
	if (mThrowAnimCoolTime <= 0.0f) {
		mThrowAnimation++;
		if (mThrowAnimation >= ThrowAllNum) {
			mThrowAnimation = 0;
		}
		mThrowAnimCoolTime = 0.3f;
		mThrowAnimation %= ThrowAllNum;
	}
}



void Player::AnimationControl(bool isStand)
{
	onGround = isStand;
	if (!onGround){
		mHandle = mJump[mJumpAnimation];
	}

	else if (CheckHitKey(KEY_INPUT_RIGHT)&& isStand || (CheckHitKey(KEY_INPUT_LEFT))&& isStand) {
		mHandle = mRun[mRunAnimation];
	}

	else {
		mHandle = mIdle[mIdleAnimation];
	}
}

void Player::Draw()
{
	DrawRotaGraph((int)mPlayer.x, (int)mPlayer.y, 1, 0, mHandle, TRUE, IsRightDir);
}
