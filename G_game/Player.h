#pragma once

// �C���N���[�h
#include "DxLib.h"

//�v���C���[�̏����ʒu
const int FirstPosX= 100;
const int FirstPosY = 100;

//�d��
const int Gravity = 1;

//�v���C���[�̃T�C�Y
const int XSize = 64;
const int YSize = 64;

//�ҋ@�A�j���[�V����
const int IdleAllNum = 2;
const int IdleXNum = 2;
const int IdleYNum = 1;

//����A�j���[�V����
const int RunAllNum = 8;
const int RunXNum = 8;
const int RunYNum = 1;

//������A�j���[�V����
const int ThrowAllNum = 6;
const int ThrowXNum = 6;
const int ThrowYNum = 1;

//�v���C���[�N���X
class Player
{
public:
	//�R���X�g���N�^
	Player();
	//�f�X�g���N�^
	~Player();

	/// <summary>
	/// ������
	/// </summary>
	void Init();

	/// <summary>
	/// deltaTime�̃Z�b�^�[
	/// </summary>
	void SetdeltaTime();

	/// <summary>
	/// deltaTime�̃Q�b�^�[
	/// </summary>
	/// <returns>deltaTime</returns>
	float GetdeltaTime() {return deltaTime; }

	/// <summary>
	/// �L�����̍��W
	/// </summary>
	void Move();
	VECTOR& GetPosition() { return mPlayer; }


	/// <summary>
	/// �ҋ@�A�j���[�V����
	/// </summary>
	void IdleAnimation();

	/// <summary>
	/// �ҋ@�A�j���[�V�����`��
	/// </summary>
	void IdleDraw();
	
	/// <summary>
	/// ����A�j���[�V�����֘A
	/// </summary>
	void RunAnimation();
	void RunDraw();

	/// <summary>
	/// �L�����̃A�j���[�V������
	/// </summary>
	void CharaAnimation();
	

private:
	//�E������
	bool IsRightDir;
	
	//Player
	VECTOR mPlayer;
	
	//�f���^�^�C���֘A
	float nowCount, prevCount;
	float deltaTime;

	//�ҋ@�A�j���[�V�����֘A
	int mIdle[IdleAllNum];
	int mIdleAnimation;
	float mIdleAnimCoolTime;

	//����A�j���\�V�����֘A
	int mRun[RunAllNum];
	int mRunAnimation;
	float mRunAnimCoolTime;

	//�����A�j���[�V�����֘A
	int mThrow[ThrowAllNum];
	int mThrowAnimation;
	float mThrowAnimCoolTime;

	
};