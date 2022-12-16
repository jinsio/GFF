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
#include "ShotDummy.h"

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

	//---プレイヤー関連インスタンス---//
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
	
	PlayerObjectManager::Update(_deltaTime);

	//---スクロール処理---//
	scroll->SetScrLR(RunSpeed);
	scroll->SetScrXY(player->GetVY());
	scroll->MoveScroll(_deltaTime,player->GetPosition());

	bg->Update();;
	bg->SetScrPos(scroll->GetScrPos());
	collision->SetScrPos(scroll->GetScrPos());
	map->SetScrPos(scroll->GetScrPos());

	if (bullet != nullptr&&(player->GetPos().x==scroll->GetscrRX())) {
		bullet->LEFTScrPos(scroll->GetScrSpeedLR(),_deltaTime);
	}

	if (bullet != nullptr && (player->GetPos().x == scroll->GetscrLX())) {
		bullet->RIGHTScrPos(scroll->GetScrSpeedLR(), _deltaTime);
	}
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
	if (bullet!=nullptr)
	{
		bullet->SetonGround(collision->ColBox(bullet->GetPosition()));
	}
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
		bullet = new Bullet(player);
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

