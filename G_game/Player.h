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
public:
	//�R���X�g���N�^
	Player();
	//�f�X�g���N�^
	~Player();

	/// <summary>
	/// �v���C���[�̕`��
	/// </summary>
	void Init();
	void SetdeltaTime();
	float GetdeltaTime() {return deltaTime; }
	void Move();

	void IdleAnimation();
	void IdleDraw();

	void RunAnimation();
	void RunDraw();

	void AllDraw();
	VECTOR& GetPosition() { return mPlayer; }

private:
	bool IsRightDir;
	VECTOR mPlayer;
	
	float nowCount, prevCount;
	float deltaTime;

	int mIdle[IdleAllNum];
	int mIdleAnimation;
	float mIdleAnimCoolTime;


	int mRun[RunAllNum];
	int mRunAnimation;
	float mRunAnimCoolTime;
	
	
};