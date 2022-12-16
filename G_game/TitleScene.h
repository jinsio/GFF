#pragma once

// インクルード
#include "SceneBase.h"

const int MaxFadein = 255;			//不透明度最大値
const int DrawBgSpeed = 5;			//背景スクロール速度
const int FadeSpeed=5;				//点滅速度

class BackGround;

/* タイトルシーン */
class TitleScene :public SceneBase
{
	BackGround * titleBg;
public:
	// コンストラクタ
	TitleScene();
	// デストラクタ
	~TitleScene();

	/// <summary>
	/// シーンの更新処理
	/// </summary>
	/// <returns>現在のシーンのポインタ</returns>
	SceneBase* Update(float _deltaTime)override;

	void TitleDisplay();


	/// <summary>
	/// シーンの描画
	/// </summary>
	void Draw()override;

private:
	int fadein;					//透明度
	VECTOR titleBgPos;				//タイトル背景座標
};

