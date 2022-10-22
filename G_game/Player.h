#pragma once

// �C���N���[�h
#include "DxLib.h"

//�v���C���[�̏����ʒu
const int FirstPosX= 100;
const int FirstPosY = 100;

const int XSize = 64;
const int YSize = 64;


const int IdleAllNum = 2;
const int IdleXNum = 2;
const int IdleYNum = 1;

const int RunAllNum = 8;
const int RunXNum = 8;
const int RunYNum = 1;

//�v���C���[�N���X
class Player
{
private:
	int mIdle[IdleAllNum];
	int mIdleAnimation;
	float idleAnimeCoolTime;

	int mRun[RunAllNum];
	int mRunAnimation;
	float RunAnimeCoolTime;
	
	float deltaTime;
	bool direction;
	
	VECTOR mPlayer;

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
	void IdleAnimation(float deltaTime);
	void RunAnimation(float deltaTime);

};