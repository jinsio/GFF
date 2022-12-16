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
	sclMaxY = 40 * 54 - 1080;
	sclMinX = -40;
	sclMinY = -40;
}

// @brief Scrollデストラクター //

Scroll::~Scroll()
{
}

// @brief Scroll移動処理 //

void Scroll::Update(float deltaTime,VECTOR& plyPos)
{
	//---プレイヤー押し戻し処理---//
	if (plyPos.x + 64 > scrollX + scrMaxW)				//右スクロール
	{
		dx = plyPos.x - (scrollX + scrMaxW);
	}
	if (plyPos.y + 64 > scrollY + scrMaxH)				//下スクロール
	{
		dy = plyPos.y - (scrollY + scrMaxH);
	}
	if (plyPos.x < scrollX + scrMinW)					//左スクロール
	{
		dx = plyPos.x - (scrollY + scrMinW);
	}
	if (plyPos.y < scrollY + scrMinH)					//上スクロール
	{
		dy = plyPos.y - (scrollY + scrMinH);
	}

	scrollX += dx;
	scrollY += dy;

	if (scrollX > sclMaxX)
	{
		scrollX = sclMaxX;
	}
	else if (scrollX < sclMinX)
	{
		scrollX = sclMinX;
	}
	if (scrollY > sclMaxY)
	{
		scrollY = sclMaxY;
	}
	else if (scrollY < sclMinY)
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