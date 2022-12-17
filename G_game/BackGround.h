#pragma once
#include<DxLib.h>
#include<vector>

const int ScreenW = 1920;
const int ScreenH = 1080;

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
	/// BackGround�`�揈��
	/// </summary>
	void Draw(int scrX,int scrY);

private:
	int bgBack;					//�w�ʃ��C���[
	int bgMid;					//�������C���[
	int bgFront;				//�O�ʃ��C���[
	int drawBgX;				//�`����WX
	int drawBgY;				//�`����WY
	VECTOR bgPos;				//�w�i���W
};

