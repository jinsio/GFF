#pragma once

// �C���N���[�h
#include "DxLib.h"
#include <vector>


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

//�ҋ@�A�j���[�V����
const int IdleAllNum = 2;
const int IdleXNum = 2;
const int IdleYNum = 1;

//����A�j���[�V����
const int RunAllNum = 8;
const int RunXNum = 8;
const int RunYNum = 1;

//������A�j���[�V����
const int ThrowAllNum = 8;
const int ThrowXNum = 8;
const int ThrowYNum = 1;

//�v���C���[�N���X
class Player
{
public:
	//�R���X�g���N�^
	Player();
	//�f�X�g���N�^
	~Player();

	// ������
	void Init();

	//�A�b�v�f�[�g
	void Update(float _deltaTime,bool isStand);
	
	// deltaTime�̃Z�b�^�[
	void SetdeltaTime();

	// deltaTime�̃Q�b�^�[
	// <returns>deltaTime
	float GetdeltaTime() {return deltaTime; }

	//�L�����̈ړ�
	void Move(bool isStand);

	// �L�����̍��W
	VECTOR& GetPosition() { return mPlayer; }

	// �ҋ@�A�j���[�V�����ݒ�
	void IdleAnimation(float _deltaTime);

	// ����A�j���[�V�����ݒ�
	void RunAnimation(float _deltaTime);

	// �����A�j���[�V�����ݒ�
	void ThrowAnimation(float _deltaTime);

	// �A�j���[�V��������
	void AnimationUpdate(float _deltaTime);

	//�`�搧��
	void AnimationControl();

	// �A�j���[�V�����`��
	void Draw();

private:
	//�E������
	bool IsRightDir;
	
	//Player
	VECTOR mPlayer;
	
	float playerVY;
	bool jumpFlag;
	int jumpButtonCount;


	//�f���^�^�C���֘A
	float nowCount, prevCount;
	float deltaTime;

	//�A�j���[�V����
	int mHandle;
	int mAnimation;

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