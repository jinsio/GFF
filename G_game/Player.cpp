// �C���N���[�h
#include "Dxlib.h"
#include "PlayScene.h"
#include "Player.h"

Player::Player():
	mPlayer(),
	pImage()
{
	//�v���C���[�̏����ʒu�̑��
	mPlayer =VGet(FirstPosX,FirstPosY,0);
	//�v���C���[�摜�̓ǂݍ���
	pImage = LoadGraph("assets/player/Player.png");
}

Player::~Player()
{
}

void Player::PlayerDraw()
{
	DrawGraph(mPlayer.x, mPlayer.y, pImage, TRUE);
}

void Player::PlayerMove()
{

}
