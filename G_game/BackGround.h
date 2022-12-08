#pragma once
#include<DxLib.h>
#include<vector>

const int LayerNum = 3;
const int screenNum = 2;

using namespace std;

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
		int bgHandle[LayerNum] = { -1,-1,-1 };		//�w�i�摜�n���h��
		float bgX[LayerNum] = {};			//���C���[���Ƃ̔w�i���WX
		float bgY[LayerNum] = {};			//���C���[���Ƃ̔w�i���WY
		int screenPos[LayerNum] = {};	//�X�N���[�����W

	};
	Bg first;
	Bg second;

	float bgScreenX;
	VECTOR bgPos;				//�w�i���W
};

