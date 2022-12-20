#pragma once

// �C���N���[�h
#include "DxLib.h"
#include <vector>
#include "PlayerObject.h"

//�v���C���[�̏����ʒu
const int FirstPosX= 400;
const int FirstPosY = 200;

//�ړ����x
const float RunSpeed = 250.0f;

//�W�����v�֘A
const float jumpPower = 12.0f;     // �W�����v�����x
const float gravity = 0.3f;    // �d��
const float maxFallSpeed = 10.0f;   // �ő嗎�����x


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

//�W�����v�A�j���[�V����
const int JumpAllNum = 8;
const int JumpXNum = 8;
const int JumpYNum = 1;

//������A�j���[�V����
const int ThrowAllNum = 8;
const int ThrowXNum = 8;
const int ThrowYNum = 1;

//�v���C���[�N���X
class Player:public PlayerObject
{
public:
	//�R���X�g���N�^
	Player();
	//�f�X�g���N�^
	~Player();

	// ������
	void Init();

	//�A�b�v�f�[�g
	void Update(float deltaTime) override;

	// deltaTime�̃Q�b�^�[
	// <returns>deltaTime
	float GetdeltaTime() {return deltaTime; }

	//�L�����������Ă��邩
	void SetonGround(bool isStand) { onGround=isStand; }

	//�L�����̈ړ�
	void Move(float deltaTime);

	// �L�����̍��W
	VECTOR& GetPosition() { return mPos; }

	//�L�����̏d��
	float GetVY() { return playerVY; }

	//�L�����̌���
	int GetDir() { return mRightDir; }


	// �ҋ@�A�j���[�V�����ݒ�
	void IdleAnimation(float _deltaTime);

	// ����A�j���[�V�����ݒ�
	void RunAnimation(float _deltaTime);

	// �����A�j���[�V�����ݒ�
	void ThrowAnimation(float _deltaTime);

	//�W�����v�A�j���[�V�����ݒ�
	void JumpAnimation(float deltaTime);

	// �A�j���[�V��������
	void AnimationUpdate(float deltaTime);
	//�`�搧��
	void AnimationControl();
	// �A�j���[�V�����`��
	void Draw(int offSetX, int offSetY)override;

private:
	float playerVY;
	bool onGround;
	int jumpButtonCount;

	bool input;

	//�f���^�^�C���֘A
	float nowCount, prevCount;
	float deltaTime;

	//�A�j���[�V����
	int mAnimation;

	//�ҋ@�A�j���[�V�����֘A
	int mIdle[IdleAllNum];
	int mIdleAnimation;
	float mIdleAnimCoolTime;

	//����A�j���\�V�����֘A
	int mRun[RunAllNum];
	int mRunAnimation;
	float mRunAnimCoolTime;

	//�W�����v�A�j���\�V�����֘A
	int mJump[JumpAllNum];
	int mJumpAnimation;
	float mJumpAnimCoolTime;
	bool jumpFlag;

	//�����A�j���[�V�����֘A
	int mThrow[ThrowAllNum];
	int mThrowAnimation;
	float mThrowAnimCoolTime;

};