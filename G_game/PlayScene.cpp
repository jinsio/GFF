// �C���N���[�h
#include "PlayScene.h"
#include "ResultScene.h"

#include "GameObjectManager.h"

#include "BackGround.h"
#include "Map.h"
#include "Collision.h"
#include "Scroll.h"

#include "Player.h"
#include "Button.h"
#include "Bullet.h"
#include "BulletNumber.h"
#include "ShotDummy.h"
#include "SkeltonBlock.h"

PlayScene::PlayScene()
    : 
	SceneBase(),
	dummy(),
	bullet()
{
	//---�X�e�[�W�֘A�C���X�^���X---//
	bg = new BackGround;
	map = new Map;
	collision = new Collision;
	scroll = new Scroll;
	block = new SkeltonBlock;

	//---�v���C���[�֘A�C���X�^���X---//
	player = new Player;
	button = new Button;
	bulletnumber = new BulletNumber;

	GameObjectManager::Initialize();
	player->Init();
	GameObjectManager::Entry(player);
}

PlayScene::~PlayScene()
{

}

SceneBase* PlayScene::Update(float _deltaTime)
{
	isStand();
	ShotFlow(_deltaTime);
	
	GameObjectManager::Update(_deltaTime);
	scroll->Update(_deltaTime, player->GetPosition());

	// �V�[���J�ڏ���(�X�y�[�X�L�[�������ƑJ�ځi���j)
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		GameObjectManager::Finalize();
		// �����𖞂����Ă����烊�U���g�V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new ResultScene();
	}

	// �V�[���J�ڏ����𖞂����Ă��Ȃ������獡�̃|�C���^��Ԃ�
	return this;
}

void PlayScene::isStand()
{
	player->SetonGround(collision->ColBox(player->GetPosition()));
	block->CheckPlayerHit(player);
	if (bullet!=nullptr)
	{
		bullet->SetonGround(collision->ColBox(bullet->GetPosition()));
		block->CheckBulletHit(bullet);
	}
}

void PlayScene::ShotFlow(float _deltaTime)
{
	if (button->ButtonStatusI()==3) {
		bulletnumber->AddBulletNumber();
	}
	
	if (bulletnumber->GetBulletNumber() > 0) 
	{
		int tmp = button->ButtonStatusP();
		if (tmp == 1) {
			dummy = new ShotDummy(player);
			GameObjectManager::Entry(dummy);
		}

		else if (tmp == 2) {
			dummy->AddRadian(_deltaTime);
			dummy->SetPos(player->GetPos());
		}

		else if (tmp == 3)
		{
			bullet = new Bullet(player);
			GameObjectManager::Entry(bullet);
			bullet->SetBulletDir(dummy->GetBulletDummyDir());
			bullet->BulletAngleSet(dummy->GetRadian());
			bulletnumber->SubBulletNumber();
			dummy->SetAlive(false);
		}
		else
		{
		}
	}
}

void PlayScene::Draw()
{
	bg->Draw(scroll->GetDrawOffSetX(), scroll->GetDrawOffSetY());
	map->MapDraw(scroll->GetDrawOffSetX(), scroll->GetDrawOffSetY());
	block->Draw(scroll->GetDrawOffSetX(), scroll->GetDrawOffSetY());

	GameObjectManager::Draw(scroll->GetDrawOffSetX(), scroll->GetDrawOffSetY());
	unsigned int Color;

	Color = GetColor(255, 255, 255);
	DrawFormatString(0, 0, Color, "�c�e i �̒l�� %d �ł�", bulletnumber->GetBulletNumber());
	
}

