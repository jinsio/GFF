#pragma once
#include<DxLib.h>

const int LayerNum = 3;
const int screenNum = 2;

/*�w�i�̃N���X*/
class BackGround
{
public:
	/// <summary>
	/// BackGround�̃R���X�g���N�^�[
	/// </summary>
	BackGround();

	/// <summary>
	/// BackGround�̃f�X�g���N�^�[
	/// </summary>
	~BackGround();

	/// <summary>
	/// BackGound�X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// BackGround�`�揈��
	/// </summary>
	void Draw();

	/// <summary>
	/// �w�i���W�̃Z�b�^�[
	/// </summary>
	/// <param name="scrPos">�X�N���[�����W</param>
	void SetScrPos(VECTOR& scrPos) { bgPos = scrPos; }

private:
	struct Bg {
		int bgHandle = -1;		//�w�i�摜�n���h��
		float bgX = 0;		//���C���[���Ƃ̔w�i���WX
		float bgY = 0;		//���C���[���Ƃ̔w�i���WY
	};
	Bg first[LayerNum];
	float bgScreenX;
	VECTOR bgPos;				//�w�i���W

};

