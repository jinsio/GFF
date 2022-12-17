#include "Scroll.h"
#include "Bullet.h"
// @brief Scrollコンストラクタ― //

Bullet* bullet;

Scroll::Scroll()
	:scrollX(0)
	,scrollY(0)
	,dx(0)
	,dy(0)
{
	sclMaxX = 40 * 162 - 1920;
	sclMaxY = 40 * 58 - 1080;
	sclMinX = 0;
	sclMinY = 0;
}

// @brief Scrollデストラクター //

Scroll::~Scroll()
{
}

// @brief Scroll移動処理 //

void Scroll::Update(float deltaTime,VECTOR& plyPos)
{
	dx = dy = 0;

	//---プレイヤー押し戻し処理---//
	if (plyPos.x +64  > scrollX + scrMaxW)				//右にスクロールする座標を超えたら
	{
		dx = plyPos.x+64 - (scrollX + scrMaxW);			//左に押し戻す
	}
	if (plyPos.y + 64 > scrollY + scrMaxH)				//下スクロール
	{
		dy = plyPos.y+64 - (scrollY + scrMaxH);
	}
	if (plyPos.x-64 < scrollX + scrMinW)					//左スクロール
	{
		dx = plyPos.x-64 - (scrollX + scrMinW);
	}
	if (plyPos.y-64 < scrollY + scrMinH)					//上スクロール
	{
		dy = plyPos.y-64 - (scrollY + scrMinH);
	}

	scrollX += dx;										//押し戻しX
	scrollY += dy;										//押し戻しY

	//---スクロール座標最大値処理---//
	if (scrollX > sclMaxX)								//右スクロール座標最大値まできたら
	{
		scrollX = sclMaxX;								//スクロール停止
	}
	else if (scrollX < sclMinX)							//左スクロール
	{
		scrollX = sclMinX;
	}
	if (scrollY > sclMaxY)								//下スクロール
	{
		scrollY = sclMaxY;
	}
	else if (scrollY < sclMinY)							//上スクロール
	{
		scrollY = sclMinY;
	}
}

// @brief スクロールの描画オフセットXを取得 //

int Scroll::GetDrawOffSetX()
{
	return static_cast<int>(scrollX);
}

// @brief スクロールの描画オフセットYを取得 //

int Scroll::GetDrawOffSetY()
{
	return static_cast<int>(scrollY);
}