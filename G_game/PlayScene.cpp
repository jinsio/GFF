// �C���N���[�h
#include "PlayScene.h"
#include "ResultScene.h"

#include "PlayerObjectManager.h"

#include "Player.h"
#include "Map.h"
#include "Collision.h"
#include "Scroll.h"
#include "Bullet.h"
#include "ShotDummy.h"
#include "Button.h"

PlayScene::PlayScene()
    : SceneBase()
	, tmpRadian(0)
{
	map = new Map;
	collision = new Collision;
	scroll = new Scroll;
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
	ShotFlow();
	/*if (button->BottunStatus()==3)
	{
		PlayerObject* bullet = new Bullet(player);
		PlayerObjectManager::Entry(bullet);
	}*/
	
	PlayerObjectManager::Update(_deltaTime);
	scroll->MoveScroll(player->GetPosition());
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

void PlayScene::ShotFlow()
{
	if (button->ButtonStatus() == 1) {
		
		
	}

	if (button->ButtonStatus() == 2) {
		ShotDummy* dummy = new ShotDummy(player);
		PlayerObjectManager::Entry(dummy);
		tmpRadian=dummy->GetRadian();
		PlayerObjectManager::Release(dummy);
	}

	if (button->ButtonStatus() == 3){
		
		Bullet* bullet = new Bullet(player);
		bullet->BulletAngleSet(tmpRadian);
		PlayerObjectManager::Entry(bullet);
		tmpRadian = 0;
	}
	
	/*if (button->ButtonStatus() == 3)
	{
		
	}*/
}

void PlayScene::Draw()
{
	map->MapDraw();
	PlayerObjectManager::Draw();
}

