#pragma once

// �C���N���[�h
#include "DxLib.h"

//�v���C���[�̏����ʒu
const int FirstPosX= 0;
const int FirstPosY = 100;

const int CharaIdleAllNum = 2;
const int CharaIdleXNum = 2;
const int CharaIdleYNum = 1;
const int CharaIdleXSize = 64;
const int CharaIdleYSize = 64;


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
	
	void Draw();
	void Move();
	void IdleAnimation();

	
private:
	int mIdle[CharaIdleAllNum];
	int pImage;
	int mIdleAnimation;
	bool direction;
	float deltaTime;
	VECTOR mPlayer;
	
};