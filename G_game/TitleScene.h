#pragma once

// �C���N���[�h
#include "SceneBase.h"

const int MaxFadein = 255;			//�s�����x�ő�l
const int DrawBgSpeed = 5;			//�w�i�X�N���[�����x
const int FadeSpeed=5;				//�_�ő��x

class BackGround;

/* �^�C�g���V�[�� */
class TitleScene :public SceneBase
{
	BackGround * titleBg;
public:
	// �R���X�g���N�^
	TitleScene();
	// �f�X�g���N�^
	~TitleScene();

	/// <summary>
	/// �V�[���̍X�V����
	/// </summary>
	/// <returns>���݂̃V�[���̃|�C���^</returns>
	SceneBase* Update(float _deltaTime)override;

	void TitleDisplay();


	/// <summary>
	/// �V�[���̕`��
	/// </summary>
	void Draw()override;

private:
	int fadein;					//�����x
	VECTOR titleBgPos;				//�^�C�g���w�i���W
};

