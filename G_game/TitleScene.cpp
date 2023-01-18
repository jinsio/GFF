// �C���N���[�h
#include "TitleScene.h"
#include "PlayScene.h"
#include"BackGround.h"
TitleScene::TitleScene()
	: SceneBase()
	,fadein(0)
	,titleBgPos{0,-1300,0}
{
	// �^�C�g���摜�̓ǂݍ���(��)
	mImage = LoadGraph("assets/scene/Title.png");
	titleBg = new BackGround;

}

TitleScene::~TitleScene()
{
}

SceneBase* TitleScene::Update(float _deltaTime)
{
	if (fadein <= 255)										//�s�����łȂ����
	{
		fadein++;											//���X�ɕs�����ɂ��Ă���
	}
	else
	{
		//---�X�N���[�����W�ݒ�---//
		titleBgPos.x += DrawBgSpeed*_deltaTime;
		titleBgPos.y=1300;

		// �V�[���J�ڏ���(�G���^�[�������ƑJ�ځi���j)
		if (CheckHitKey(KEY_INPUT_RETURN))
		{
			// �����𖞂����Ă�����v���C�V�[���𐶐����Ă��̃|�C���^��Ԃ�
			return new PlayScene();
		}
	}


	


	// �V�[���J�ڏ����𖞂����Ă��Ȃ������獡�̃|�C���^��Ԃ�
	return this;
}

void TitleScene::TitleDisplay()
{
}

void TitleScene::Draw()
{
	titleBg->Draw(titleBgPos.x, titleBgPos.y);					//�w�i�X�N���[���`��
	// �^�C�g���̕`��
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, fadein);			//�t�F�[�h�C��
	DrawRotaGraph( 960, 400, 1.5, 0, mImage,1,0);				//�摜�`��
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, fadein);			//�ȍ~�̉摜���[�h��W���ɐݒ�
}
