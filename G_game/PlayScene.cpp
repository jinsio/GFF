// �C���N���[�h
#include "PlayScene.h"
#include "ResultScene.h"

#include "PlayerObjectManager.h"

#include"BackGround.h"
#include "Map.h"
#include "Collision.h"
#include "Scroll.h"

#include "Player.h"
#include "Button.h"
#include "Bullet.h"
#include "ShotDummy.h"

PlayScene::PlayScene()
    : 
	SceneBase(),
	dummy()
{
	//---�X�e�[�W�֘A�C���X�^���X---//
	bg = new BackGround;
	map = new Map;
	collision = new Collision;
	scroll = new Scroll;

	//---�v���C���[�֘A�C���X�^���X---//
	player = new Player;
	button = new Button;
	PlayerObjectManager::Initialize();
	player->Init();
	PlayerObjectManager::Entry(player);
}

PlayScene::~PlayScene()
{

}

SceneBase* PlayScene::Update(float _deltaTime)
{
	isStand();
	ShotFlow(_deltaTime);
	/*if (button->BottunStatus()==3)
	{
		PlayerObject* bullet = new Bullet(player);
		PlayerObjectManager::Entry(bullet);
	}*/
	
	PlayerObjectManager::Update(_deltaTime);

	//---�X�N���[������---//
	scroll->MoveScroll(player->GetPosition());
	bg->SetScrPos(scroll->GetScrPos());
	collision->SetScrPos(scroll->GetScrPos());
	map->SetScrPos(scroll->GetScrPos());
	
	// �V�[���J�ڏ���(�X�y�[�X�L�[�������ƑJ�ځi���j)
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		PlayerObjectManager::Finalize();
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

void PlayScene::ShotFlow(float _deltaTime)
{
	int tmp = button->ButtonStatus();
	if (tmp == 1) {
			dummy = new ShotDummy(player);
			PlayerObjectManager::Entry(dummy);
	}

	else if (tmp == 2) {
		dummy->AddRadian(_deltaTime);
		dummy->SetPos(player->GetPos());
	}

	else if (tmp == 3)
	{
		Bullet* bullet = new Bullet(player);
		PlayerObjectManager::Entry(bullet);
		bullet->SetBulletDir(dummy->GetBulletDummyDir());
		bullet->BulletAngleSet(dummy->GetRadian());
		dummy->SetAlive(false);
	}
	else
	{
	}
}

void PlayScene::Draw()
{
	bg->Draw();
	map->MapDraw();
	PlayerObjectManager::Draw();
}

