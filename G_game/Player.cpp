// インクルード
#include "Dxlib.h"
#include "PlayScene.h"
#include "Player.h"

Player::Player():
	mPlayer(),
	pImage(0),
	mIdle{},
	mIdleAnimation(),
	deltaTime(),
	direction(FALSE)
{
	
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
	LoadDivGraph("assets/player/idle.png", CharaIdleAllNum, CharaIdleXNum, CharaIdleYNum, CharaIdleXSize, CharaIdleYSize, mIdle);
}

void Player::Draw()
{
	IdleAnimation();
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

void Player::IdleAnimation()
{
	nowcount = GetNowCount();
	deltaTime = (nowcount - prevCount) / 1000.0f;
	mIdleAnimation %= CharaIdleAllNum;

	if (direction) {
		DrawGraph(mPlayer.x, mPlayer.y,mIdle[mIdleAnimation], TRUE);
	}

	if (!direction){
		DrawTurnGraph(mPlayer.x, mPlayer.y,mIdle[mIdleAnimation], TRUE);
	}
	prevCount = nowcount;
}
