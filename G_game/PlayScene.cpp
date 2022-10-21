// インクルード
#include "PlayScene.h"
#include "ResultScene.h"
#include "Player.h"
#include "Map.h"


PlayScene::PlayScene()
    : SceneBase()
{
    // プレイ画像の読み込み(仮)
    mImage = LoadGraph("assets/scene/Play.png");
	map = new Map;
	player = new Player;
}

PlayScene::~PlayScene()
{
}

SceneBase* PlayScene::Update(float _deltaTime)
{
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
	map->MapMove();
	player->Move();
	player->Draw();
}

