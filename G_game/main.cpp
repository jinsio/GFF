//-----------------------------------------------------------------------------
// @brief  メイン処理.
// 2022 Team G(変更可)
//-----------------------------------------------------------------------------

// インクルード
#include "DxLib.h"
#include "SceneBase.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "PlayerObjectManager.h"
#include "Player.h"
#include "Button.h"
#include <iostream>
//-----------------------------------------------------------------------------
// @brief  メイン関数.
//-----------------------------------------------------------------------------
using namespace std;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// 画面モードのセット
	SetGraphMode(ScreenBeside, ScreenVertical, ColorDepth);
	ChangeWindowMode(TRUE);

	// DXライブラリの初期化
	if (DxLib_Init() == -1)
	{
		// エラーが起きたら直ちに終了
		return -1;
	}

	//PlayerObjectManager::Initialize();
	// デルタタイム管理用の変数をセット
	LONGLONG nowTime;
	LONGLONG time;
	float deltaTime;

	// システム時間を取得
	time = GetNowHiPerformanceCount();

	//	最初の経過時間は仮に0.0000001f秒にしておく
	deltaTime = 0.000001f;

	// 現在のシーンを生成
	SceneBase* nowScene = new TitleScene();

	// Escキーが押されるか、ウィンドウが閉じられるまでループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// シーンの更新処理
		// Updateの戻り値で次のシーンのポインタが返ってくる
		// tmpSceneに返ってきたシーンのポインタを代入
		SceneBase* tmpScene = nowScene->Update(deltaTime);

		// nowScene(現在)とtmpSceneが異なっていたら
		if (nowScene != tmpScene)
		{
			// 現在のシーンを解放
			delete nowScene;
			// nowSceneにtmpSceneを代入
			nowScene = tmpScene;
		}
		// 画面を初期化する
		ClearDrawScreen();

		// 現在のシーンを描画
		nowScene->Draw();
		// 裏画面の内容を表画面に反映させる
		ScreenFlip();

		// 現在のシステム時間を取得
		nowTime = GetNowHiPerformanceCount();

		// 前回取得した時間からの経過時間を秒に変換してセット
		// ( GetNowHiPerformanceCount で取得できる値はマイクロ秒単位なので 1000000 で割ることで秒単位になる )
		deltaTime = (nowTime - time) / 1000000.0f;

		// 今回取得した時間を保存
		time = nowTime;
		
	}

	// シーンの削除
	delete nowScene;
	/*PlayerObjectManager::Finalize();*/

	// DXライブラリの後始末
	DxLib_End();

	// ソフトの終了
	return 0;
}