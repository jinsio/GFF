#include "Dxlib.h"
#include "PlayScene.h"
#include "Player.h"


Player::Player():
	mPlayer(),
	mIdle{},
	mIdleAnimation(),
	idleAnimeCoolTime(0.5),
	direction(TRUE),
	mRun{},
	mRunAnimation(),
	RunAnimeCoolTime(),
	deltaTime(0)

{
	//プレイヤーの初期位置の代入
	mPlayer.x = FirstPosX;
	mPlayer.y = FirstPosY;
	//プレイヤー画像の読み込み
	LoadDivGraph("assets/player/idle.png", IdleAllNum, IdleXNum, IdleYNum, XSize, YSize,mIdle);
	LoadDivGraph("assets/player/player_anim.png", RunAllNum, RunXNum, RunYNum, XSize, YSize, mRun);
	
}

Player::~Player()
{
}

void Player::Init()
{
	//プレイヤーの初期位置の代入
	mPlayer.x = FirstPosX;
	mPlayer.y = FirstPosY;
}



void Player::Move()
{
	if (CheckHitKey(KEY_INPUT_RIGHT)){
		direction = TRUE;
	}
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		direction = FALSE;
	}
}

void Player::IdleAnimation(float deltaTime)
{
	idleAnimeCoolTime -= deltaTime;
	if (idleAnimeCoolTime <= 0)
	{
		mIdleAnimation++;
		idleAnimeCoolTime = 0.5;
		
		if(mIdleAnimation>2){ 
		mIdleAnimation = 0;
		}
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "FPS:%d", &deltaTime);
	
}

void Player::RunAnimation(float deltaTime)
{
	if (CheckHitKey(KEY_INPUT_RIGHT) || CheckHitKey(KEY_INPUT_LEFT))
	{
			mRunAnimation++;
			idleAnimeCoolTime = 1;

			if (mRunAnimation > 8) {
				mRunAnimation = 0;
			}
			
	}
}

void Player::Draw()
{
	IdleAnimation(deltaTime);
	DrawRotaGraph((int)mPlayer.x, (int)mPlayer.y, 1.0f, 0, mIdle[mIdleAnimation], TRUE, !direction);
	//DrawRotaGraph((int)mPlayer.x, (int)mPlayer.y, 1.0f, 0, mRun[mRunAnimation], TRUE, !direction);
}