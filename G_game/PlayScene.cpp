// インクルード
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
	// シーン遷移条件(スペースキーを押すと遷移（仮）)
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		// 条件を満たしていたらリザルトシーンを生成してそのポインタを返す
		return new ResultScene();
	}

	// シーン遷移条件を満たしていなかったら今のポインタを返す
	return this;
}

void PlayScene::Draw()
{
	map->MapDraw();
	player->Draw();
	bullet->Draw();
}

