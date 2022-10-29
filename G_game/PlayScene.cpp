// インクルード
#include "PlayScene.h"
#include "ResultScene.h"
#include "Player.h"
#include "Map.h"
#include"Collision.h"


PlayScene::PlayScene()
    : SceneBase()
{
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
	player->SetdeltaTime();
	collision->ColBox(player->GetPosition());
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
	player->AllDraw();
}

