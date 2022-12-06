#include "BackGround.h"

// @brief BackGroundのコンストラクター //

BackGround::BackGround()
    :bgHandle{-1,-1,-1}
    ,bgX{0,0,0}
    ,bgY{0,0,0}
    ,bgScreenX(0)
{
    bgHandle[0] = LoadGraph("assets/BackGround/R2_distantView.png");    //背面レイヤー
    bgHandle[1] = LoadGraph("assets/BackGround/R2_middleView.png");     //中央レイヤー
    bgHandle[2] = LoadGraph("assets/BackGround/R2_foreGround.png");     //前面レイヤー
}

// @brief BackGroundのデストラクタ― //

BackGround::~BackGround()
{
    for (int i = 0; i < LayerNum; i++)          //レイヤーの枚数分for文を回す
    {
        if (bgHandle[i] != -1)                  //中身が入っていたら
        {
            DeleteGraph(bgHandle[i]);           //空にする
        }
    }
}

// @brief BackGround更新処理 //

void BackGround::Update()
{

    for (int i = 0; i < LayerNum; i++)
    {
        if (bgX[i] <= 1920)
        {
            bgX[i] += 1920;
        }
    }
}

// @brief BackGround描画処理 //

void BackGround::Draw()
{

    for (int i = 0; i < LayerNum; i++)
    {
        bgX[i] = bgPos.x * (1.5f * i) ;
        bgY[i] = bgPos.y;
        DrawGraph(bgX[i], bgY[i], bgHandle[i], TRUE);
    }
}