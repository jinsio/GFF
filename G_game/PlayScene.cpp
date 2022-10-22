// インクルード
#include "PlayScene.h"
#include "ResultScene.h"
#include "Player.h"
#include "Map.h"

PlayScene::PlayScene()
    : SceneBase()
	,deltaTime(0)
	, prevTime(0)
	, nowTime(0)
{
    // プレイ画像の読み込み(仮)
	map = new Map;
	player = new Player;
	player->Init();
}

PlayScene::~PlayScene()
{
}

SceneBase* PlayScene::Update(float _deltaTime)
{
	nowTime = (float)GetNowCount();
	deltaTime = (nowTime - prevTime) / 1000.0f;
	prevTime = nowTime;

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

