#pragma once

// インクルード
#include "DxLib.h"

//プレイヤーの初期位置
const int FirstPosX= 325;
const int FirstPosY = 100;

const int LeftPosX = 162;
const int MiddlePosX = 325;
const int RightPosX = 487;

//プレイヤークラス
class Player
{
public:
	//コンストラクタ
	Player();
	//デストラクタ
	~Player();
	


	/// <summary>
	/// プレイヤーの描画
	/// </summary>
	void PlayerDraw();

	void PlayerMove();

	
private:
	
	int pImage;
	VECTOR mPlayer;
};