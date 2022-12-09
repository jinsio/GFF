#include "Scroll.h"

// @brief Scrollコンストラクタ― //

Scroll::Scroll()
	:scrRX(750)
	,scrRY(450)
	,scrLX(530)
	,scrLY(190)
	,scrPos()
{
}

// @brief Scrollデストラクター //

Scroll::~Scroll()
{
}

// @brief Scroll移動処理 //

void Scroll::MoveScroll(float deltaTime,VECTOR& plyPos)
{
	if (plyPos.x > scrRX&&scrPos.x>=-scrMaxW)		//プレイヤーがスクロールする位置まで来たら
	{
		plyPos.x = scrRX;							//プレイヤーがの位置は固定
		scrPos.x -= scrSpeedLR*deltaTime/10;						//背景座標をスクロール
	}
	if (plyPos.y > scrRY&&scrPos.y>=-scrMaxH)
	{
		plyPos.y = scrRY;
		scrPos.y -= scrSpeedXY*deltaTime/10;
	}
	if (plyPos.x < scrLX && scrPos.x <= scrMinW)
	{
		plyPos.x = scrLX;
		scrPos.x += scrSpeedLR*deltaTime/10;
	}
	if (plyPos.y < scrLY && scrPos.y <= scrMinH)
	{
		plyPos.y = scrLY;
		scrPos.y -= scrSpeedXY*deltaTime/10;
	}
}