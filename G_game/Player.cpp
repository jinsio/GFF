// インクルード
#include "Dxlib.h"
#include "PlayScene.h"
#include "Player.h"


Player::Player():
	mPlayer(),
	mHandle{0},
	mAnimation(),
	mIdle{},
	mIdleAnimation(0),
	mIdleAnimCoolTime(1.0f),
	mRun{},
	mRunAnimation(0),
	mRunAnimCoolTime(0.2f),
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
}

void Player::Update(float _deltaTime)
{
	Move();
	AnimationUpdate(_deltaTime);
}

void Player::SetdeltaTime()
{	
	nowCount = (float)GetNowCount();
	deltaTime = (nowCount - prevCount) / 1000.0f;
	prevCount = nowCount;
}

void Player::AnimationUpdate(float _deltaTime)
{
	IdleAnimation(_deltaTime);
	RunAnimation(_deltaTime);
	ThrowAnimation(_deltaTime);
	AnimationControl();
}




void Player::Move()
{
	mPlayer.y += Gravity;
	if (CheckHitKey(KEY_INPUT_RIGHT)){
		IsRightDir = FALSE;
	}

	else if (CheckHitKey(KEY_INPUT_LEFT)) {
		IsRightDir = TRUE;
	}


	if (CheckHitKey(KEY_INPUT_UP)) {
		mPlayer.y -= 1;
	}
	else if (CheckHitKey(KEY_INPUT_DOWN)) {
		mPlayer.y += 1;
	}
	else if (CheckHitKey(KEY_INPUT_LEFT)) {
		mPlayer.x -= 1;
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT)) {
		mPlayer.x += 1;
	}
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

//void Player::ThrowDraw()
//{
//	DrawRotaGraph((int)mPlayer.x, (int)mPlayer.y, 1, 0, mThrow[mThrowAnimation], TRUE, IsRightDir);
//}


void Player::AnimationControl()
{
	if (CheckHitKey(KEY_INPUT_RIGHT)|| (CheckHitKey(KEY_INPUT_LEFT))) {
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
