#pragma once

// �C���N���[�h
#include "DxLib.h"

//�v���C���[�̏����ʒu
const int FirstPosX= 0;
const int FirstPosY = 100;

const int IdleAllNum = 2;
const int IdleXNum = 2;
const int IdleYNum = 1;
const int XSize = 64;
const int YSize = 64;


//�v���C���[�N���X
class Player
{
public:
	//�R���X�g���N�^
	Player();
	//�f�X�g���N�^
	~Player();

	/// <summary>
	/// �v���C���[�̕`��
	/// </summary>
	void Init();
	void Draw();
	void Move();
	void IdleAnimation();

private:
	int mIdle[IdleAllNum];
	int pImage;
	int mIdleAnimation;
	bool direction;
	int nowcount, prevCount;
	float deltaTime;
	VECTOR mPlayer;
	
};