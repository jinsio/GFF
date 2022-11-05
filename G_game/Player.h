#pragma once

// �C���N���[�h
#include "DxLib.h"

//�v���C���[�̏����ʒu
const int FirstPosX= 100;
const int FirstPosY = 100;

//�W�����v�֘A
const float jumpPower = 15.0f;     // �W�����v�����x
const float gravity = 1.0f;    // �d��
const float maxFallSpeed = 2.0f;   // �ő嗎�����x

//�v���C���[�̃T�C�Y
const int XSize = 64;
const int YSize = 64;

const int IdleAllNum = 2;
const int IdleXNum = 2;
const int IdleYNum = 1;

const int RunAllNum = 8;
const int RunXNum = 8;
const int RunYNum = 1;

class Collision;

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
	void SetdeltaTime();
	float GetdeltaTime() {return deltaTime; }
	void Move(bool isStand);

	void IdleAnimation();
	void IdleDraw();

	void RunAnimation();
	void RunDraw();

	void AllDraw();
	VECTOR& GetPosition() { return mPlayer; }


private:
	bool IsRightDir;
	VECTOR mPlayer;
	
	float playerVY;
	bool jumpFlag;
	int jumpButtonCount;

	float nowCount, prevCount;
	float deltaTime;

	int mIdle[IdleAllNum];
	int mIdleAnimation;
	float mIdleAnimCoolTime;


	int mRun[RunAllNum];
	int mRunAnimation;
	float mRunAnimCoolTime;
	
	
};