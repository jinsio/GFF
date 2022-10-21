// �C���N���[�h
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
	//�v���C���[�̏����ʒu�̑��
	mPlayer.x = FirstPosX;
	mPlayer.y = FirstPosY;
	//�v���C���[�摜�̓ǂݍ���
	LoadDivGraph("assets/player/idle.png", IdleAllNum, IdleXNum, IdleYNum, XSize, YSize,mIdle);
}

Player::~Player()
{
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

	mIdleAnimation %= IdleAllNum;

	if (direction) {
		DrawGraph(mPlayer.x, mPlayer.y,mIdle[mIdleAnimation], TRUE);
	}

	if (!direction){
		DrawTurnGraph(mPlayer.x, mPlayer.y,mIdle[mIdleAnimation], TRUE);
	}

	
}
