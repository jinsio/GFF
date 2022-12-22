// インクルード
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
#include "BulletNumber.h"
#include "ShotDummy.h"
#include "SkeltonBlock.h"

PlayScene::PlayScene()
    : 
	SceneBase(),
	dummy(),
	bullet()
{
	//---ステージ関連インスタンス---//
	bg = new BackGround;
	map = new Map;
	collision = new Collision;
	scroll = new Scroll;
	block = new SkeltonBlock;

	//---プレイヤー関連インスタンス---//
	player = new Player;
	button = new Button;
	bulletnumber = new BulletNumber;

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
	
	PlayerObjectManager::Update(_deltaTime);
	scroll->Update(_deltaTime, player->GetPosition());

	// シーン遷移条件(スペースキーを押すと遷移（仮）)
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		PlayerObjectManager::Finalize();
		// 条件を満たしていたらリザルトシーンを生成してそのポインタを返す
		return new ResultScene();
	}

	// シーン遷移条件を満たしていなかったら今のポインタを返す
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
			PlayerObjectManager::Entry(dummy);
		}

		else if (tmp == 2) {
			dummy->AddRadian(_deltaTime);
			dummy->SetPos(player->GetPos());
		}

		else if (tmp == 3)
		{
			bullet = new Bullet(player);
			PlayerObjectManager::Entry(bullet);
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

	PlayerObjectManager::Draw(scroll->GetDrawOffSetX(), scroll->GetDrawOffSetY());
	unsigned int Color;

	Color = GetColor(255, 255, 255);
	DrawFormatString(0, 0, Color, "残弾 i の値は %d です", bulletnumber->GetBulletNumber());
	
}

