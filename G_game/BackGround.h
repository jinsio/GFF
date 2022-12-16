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
	void Draw(int scrX,int scrY);

private:
	int bgBack;
	int bgMid;
	int bgFront;
	VECTOR bgPos;				//�w�i���W
};

