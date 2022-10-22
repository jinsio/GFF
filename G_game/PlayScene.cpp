// �C���N���[�h
#include "PlayScene.h"
#include "ResultScene.h"
#include "Player.h"
#include "Map.h"
#include"Collision.h"


PlayScene::PlayScene()
    : SceneBase()
{
    // �v���C�摜�̓ǂݍ���(��)
    mImage = LoadGraph("assets/scene/Play.png");
	map = new Map;
	collision = new Collision;
	player = new Player;
	player->Init();
}

PlayScene::~PlayScene()
{
}

SceneBase* PlayScene::Update(float _deltaTime)
{
	// �V�[���J�ڏ���(�X�y�[�X�L�[�������ƑJ�ځi���j)
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		// �����𖞂����Ă����烊�U���g�V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new ResultScene();
	}

	// �V�[���J�ڏ����𖞂����Ă��Ȃ������獡�̃|�C���^��Ԃ�
	return this;
}

void PlayScene::Draw()
{
	map->MapDraw();
	map->MapMove();
	collision->ColBox(player->GetPosition());
	player->Move();
	player->Draw();
}

