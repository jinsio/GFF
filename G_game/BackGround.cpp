#include "BackGround.h"

// @brief BackGroundのコンストラクター //

BackGround::BackGround()
    :bgPos()
    ,drawBgX(0)
    ,drawBgY(0)
{
    bgBack = LoadGraph("assets/BackGround/R2_distantView.png");    //背面レイヤー
    bgMid = LoadGraph("assets/BackGround/R2_middleView.png");     //中央レイヤー
    bgFront = LoadGraph("assets/BackGround/R2_foreGround.png");     //前面レイヤー
}

// @brief BackGroundのデストラクタ― //

BackGround::~BackGround()
{
    DeleteGraph(bgBack);
    DeleteGraph(bgMid);
    DeleteGraph(bgFront);
}

// @brief BackGround描画処理 //

void BackGround::Draw(int scrX,int scrY)
{
    //---スクロール座標反映---//
    drawBgX = bgPos.x - scrX;
    drawBgY = bgPos.y - scrY;

    //---背面レイヤー描画---//
    DrawGraph(drawBgX % ScreenW, drawBgY, bgBack, TRUE);
    DrawGraph(drawBgX % ScreenW + ScreenW, drawBgY, bgBack, TRUE);
    
    //---中央レイヤー描画---//
    DrawGraph(drawBgX * 2 % ScreenW, drawBgY, bgMid, TRUE);
    DrawGraph(drawBgX * 2 % ScreenW + ScreenW, drawBgY, bgMid, TRUE);
    
    //---前面レイヤー描画---//
    DrawGraph(drawBgX * 3 % ScreenW, drawBgY, bgFront, TRUE);
    DrawGraph(drawBgX * 3 % ScreenW + ScreenW, drawBgY, bgFront, TRUE);
}