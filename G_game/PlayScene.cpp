// �C���N���[�h
#include "PlayScene.h"
#include "ResultScene.h"

#include "PlayerObjectManager.h"

#include "Player.h"
#include "Map.h"
#include "Collision.h"
#include"Scroll.h"
#include "Bullet.h"

PlayScene::PlayScene()
    : SceneBase()
{
	map = new Map;
	collision = new Collision;
	scroll = new Scroll;

	player = new Player;
	PlayerObjectManager::Entry(player);

	bullet = nullptr;
	
	player->Init();
	
}

PlayScene::~PlayScene()
{
}

SceneBase* PlayScene::Update(float _deltaTime)
{
	isStand();
	if (CheckHitKey(KEY_INPUT_S))
	{
		Bullet* bullet = new Bullet(player);
		PlayerObjectManager::Entry(bullet);
	}
	
	PlayerObjectManager::Update(_deltaTime);
	scroll->MoveScroll(player->GetPosition(), map->GetPosition());
	//player->Update(_deltaTime);
	//bullet->Update(_deltaTime);
	// �V�[���J�ڏ���(�X�y�[�X�L�[�������ƑJ�ځi���j)
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		// �����𖞂����Ă����烊�U���g�V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new ResultScene();
	}

	// �V�[���J�ڏ����𖞂����Ă��Ȃ������獡�̃|�C���^��Ԃ�
	return this;
}

void PlayScene::isStand()
{
	player->SetonGround(collision->ColBox(player->GetPosition()));
}

void PlayScene::SetBullet()
{
	bullet->SetBulletPos(player->GetPos());
	bullet->SetBulletDir(player->GetDir());
}

void PlayScene::Draw()
{
	map->MapDraw();
	PlayerObjectManager::Draw();
}

