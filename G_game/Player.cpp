// インクルード
#include "Dxlib.h"
#include "PlayScene.h"
#include "Player.h"
#include "Bullet.h"

Player::Player():
	PlayerObject(PlayerObjectTag::Player),
	playerVY(0),
	jumpFlag(false),
	onGround(false),
	input(true),
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
	prevCount(0.0f)
{
	
}

Player::~Player()
{
}

void Player::Init()
{
	//プレイヤーの初期位置の代入
	mPos.x = FirstPosX;
	mPos.y = FirstPosY;
	//プレイヤー画像の読み込み
	LoadDivGraph("assets/player/idle.png", IdleAllNum, IdleXNum, IdleYNum, XSize, YSize, mIdle);
	LoadDivGraph("assets/player/player_anim.png", RunAllNum, RunXNum, RunYNum, XSize, YSize, mRun);
	LoadDivGraph("assets/player/Throw.png", ThrowAllNum, ThrowXNum, ThrowYNum, XSize, YSize, mThrow);
	LoadDivGraph("assets/player/Jump.png", JumpAllNum, JumpXNum, JumpYNum, XSize, YSize, mJump);
}

void Player::Update(float deltaTime)
{
	Move(deltaTime);
	AnimationUpdate(deltaTime);
}


void Player::SetdeltaTime()
{	
	nowCount = (float)GetNowCount();
	deltaTime = (nowCount - prevCount) / 1000.0f;
	prevCount = nowCount;
}


void Player::AnimationUpdate(float deltaTime)
{
	IdleAnimation(deltaTime);
	RunAnimation(deltaTime);
	ThrowAnimation(deltaTime);
	JumpAnimation(deltaTime);
	AnimationControl();
}



void Player::Move(float deltaTime)
{
		if (CheckHitKey(KEY_INPUT_RIGHT)) {
			mRightDir = FALSE;
			mPos.x += RunSpeed*deltaTime;
		}
		else if (CheckHitKey(KEY_INPUT_LEFT)) {
			mRightDir = TRUE;
			mPos.x -= RunSpeed * deltaTime;
		}
	if (onGround) {
		if (CheckHitKey(KEY_INPUT_J))
		{

			jumpFlag = true;
			if (jumpFlag)
			{
				playerVY = -jumpPower;
				jumpFlag = false;
			}
		}
		else {
			playerVY = 0;
		}
	}
	else if (!jumpFlag)
	{
		playerVY += gravity;
		if (playerVY > maxFallSpeed)
		{
			playerVY = maxFallSpeed;
		}
	}
	mPos.y += playerVY;
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



void Player::JumpAnimation(float deltaTime)
{
	if (!onGround)
	{
		mJumpAnimCoolTime -= deltaTime;
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




void Player::AnimationControl()
{
	if (!onGround) {
		mHandle = mJump[mJumpAnimation];
	}

	else if (CheckHitKey(KEY_INPUT_RIGHT) && onGround || (CheckHitKey(KEY_INPUT_LEFT)) && onGround) {
		mHandle = mRun[mRunAnimation];
	}

	else {
		mHandle = mIdle[mIdleAnimation];
	}
}

void Player::Draw()
{
	DrawRotaGraph((int)mPos.x, (int)mPos.y, 2, 0, mHandle, TRUE, mRightDir);
}
