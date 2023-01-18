// インクルード
#include "TitleScene.h"
#include "PlayScene.h"
#include"BackGround.h"
TitleScene::TitleScene()
	: SceneBase()
	,fadein(0)
	,titleBgPos{0,-1300,0}
{
	// タイトル画像の読み込み(仮)
	mImage = LoadGraph("assets/scene/Title.png");
	titleBg = new BackGround;

}

TitleScene::~TitleScene()
{
}

SceneBase* TitleScene::Update(float _deltaTime)
{
	if (fadein <= 255)										//不透明でなければ
	{
		fadein++;											//徐々に不透明にしていく
	}
	else
	{
		//---スクロール座標設定---//
		titleBgPos.x += DrawBgSpeed*_deltaTime;
		titleBgPos.y=1300;

		// シーン遷移条件(エンターを押すと遷移（仮）)
		if (CheckHitKey(KEY_INPUT_RETURN))
		{
			// 条件を満たしていたらプレイシーンを生成してそのポインタを返す
			return new PlayScene();
		}
	}


	


	// シーン遷移条件を満たしていなかったら今のポインタを返す
	return this;
}

void TitleScene::TitleDisplay()
{
}

void TitleScene::Draw()
{
	titleBg->Draw(titleBgPos.x, titleBgPos.y);					//背景スクロール描画
	// タイトルの描画
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, fadein);			//フェードイン
	DrawRotaGraph( 960, 400, 1.5, 0, mImage,1,0);				//画像描画
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, fadein);			//以降の画像モードを標準に設定
}
