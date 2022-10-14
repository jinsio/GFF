// インクルード
#include "Dxlib.h"
#include "PlayScene.h"
#include "Player.h"

Player::Player():
	mPlayer(),
	pImage()
{
	//プレイヤーの初期位置の代入
	mPlayer =VGet(FirstPosX,FirstPosY,0);
	//プレイヤー画像の読み込み
	pImage = LoadGraph("data/assets/Player.png");
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
