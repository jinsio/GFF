#include "BackGround.h"

// @brief BackGroundのコンストラクター //

BackGround::BackGround()
    :bgScreenX(0)
{
    first.bgHandle[0] = LoadGraph("assets/BackGround/R2_distantView.png");    //背面レイヤー
    first.bgHandle[1] = LoadGraph("assets/BackGround/R2_middleView.png");     //中央レイヤー
    first.bgHandle[2] = LoadGraph("assets/BackGround/R2_foreGround.png");     //前面レイヤー
}

// @brief BackGroundのデストラクタ― //

BackGround::~BackGround()
{
    for (int i = 0; i < LayerNum; i++)          //レイヤーの枚数分for文を回す
    {
        if (first.bgHandle[i] != -1)                  //中身が入っていたら
        {
            DeleteGraph(first.bgHandle[i]);           //空にする
        }
    }
}

// @brief BackGround更新処理 //

void BackGround::Update()
{
    for (int i = 0; i < LayerNum; i++)
    {
        
        first.bgX[i] = bgPos.x * (1.5 * i+0.5f);
        first.screenPos[i] = first.bgX[i];
        first.bgY[i] = bgPos.y;

    }

    for (int j = 0; j < LayerNum; j++)
    {
        second.bgX[j] = bgPos.x * (1.5 * j+0.5f);
        second.screenPos[j] = second.bgX[j];
        second.bgY[j] = bgPos.y;
    }
}

// @brief BackGround描画処理 //

void BackGround::Draw()
{

    for (int i = 0; i < LayerNum; i++)
    {  
        DrawGraph(first.screenPos[i] % 1920, first.bgY[i], first.bgHandle[i], TRUE);
        DrawGraph(second.screenPos[i] % 1920 + 1920, first.bgY[i], first.bgHandle[i], TRUE);
    }
}