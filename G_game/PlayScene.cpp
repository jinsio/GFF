// �C���N���[�h
#include "PlayScene.h"
#include "ResultScene.h"
#include "Player.h"
#include "Map.h"
#include "Collision.h"
#include "Bullet.h"

PlayScene::PlayScene()
    : SceneBase()
{
	map = new Map;
	collision = new Collision;
	player = new Player;
	bullet = new Bullet;
	player->Init();
}

PlayScene::~PlayScene()
{
}

SceneBase* PlayScene::Update(float _deltaTime)
{
	player->Update(_deltaTime,collision->ColBox(player->GetPosition()));
	bullet->Update(player->GetPosition(),player->GetDir());
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
	player->Draw();
	bullet->Draw();
}

