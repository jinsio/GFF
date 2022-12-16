#include "BackGround.h"

// @brief BackGroundのコンストラクター //

BackGround::BackGround()
    :bgPos()
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

// @brief BackGround更新処理 //

void BackGround::Update()
{

}

// @brief BackGround描画処理 //

void BackGround::Draw(int scrX,int scrY)
{

    for (int i = 0; i < LayerNum; i++)
    {  
        DrawGraph(bgPos.x-scrX % 1920, bgPos.y-scrY, bgBack, TRUE);
        DrawGraph(bgPos.x - (scrX*2) % 1920, bgPos.y - scrY, bgMid, TRUE);
        DrawGraph(bgPos.x - (scrX*3) % 1920, bgPos.y - scrY, bgFront, TRUE);
        //DrawGraph(1920+second.screenPos[i]+second.bgX[i] % 1920, bgPos.y, first.bgHandle[i], TRUE);
    }
}