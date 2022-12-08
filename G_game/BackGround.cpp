#include "BackGround.h"

// @brief BackGroundのコンストラクター //

BackGround::BackGround()
    :bgScreenX(0)
{
    first[0].bgHandle = LoadGraph("assets/BackGround/R2_distantView.png");    //背面レイヤー
    first[1].bgHandle = LoadGraph("assets/BackGround/R2_middleView.png");     //中央レイヤー
    first[2].bgHandle = LoadGraph("assets/BackGround/R2_foreGround.png");     //前面レイヤー
}

// @brief BackGroundのデストラクタ― //

BackGround::~BackGround()
{
    for (int i = 0; i < LayerNum; i++)          //レイヤーの枚数分for文を回す
    {
        if (first[i].bgHandle != -1)                  //中身が入っていたら
        {
            DeleteGraph(first[i].bgHandle);           //空にする
        }
    }
}

// @brief BackGround更新処理 //

void BackGround::Update()
{
    for (int i = 0; i < LayerNum; i++)
    {
        if (first[i].bgX <= -1920)
        {
            first[i].bgX = 1920;
        }
        first[i].bgX = bgPos.x * (1.5 * i);
        first[i].bgY = bgPos.y;
    }
}

// @brief BackGround描画処理 //

void BackGround::Draw()
{

    for (int i = 0; i < LayerNum; i++)
    {  
        DrawGraph(first[i].bgX, first[i].bgY, first[i].bgHandle, TRUE);
    }
}