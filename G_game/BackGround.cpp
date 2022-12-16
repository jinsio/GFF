#include "BackGround.h"

// @brief BackGround�̃R���X�g���N�^�[ //

BackGround::BackGround()
    :bgPos()
{
    bgBack = LoadGraph("assets/BackGround/R2_distantView.png");    //�w�ʃ��C���[
    bgMid = LoadGraph("assets/BackGround/R2_middleView.png");     //�������C���[
    bgFront = LoadGraph("assets/BackGround/R2_foreGround.png");     //�O�ʃ��C���[
}

// @brief BackGround�̃f�X�g���N�^�\ //

BackGround::~BackGround()
{
    DeleteGraph(bgBack);
    DeleteGraph(bgMid);
    DeleteGraph(bgFront);
}

// @brief BackGround�X�V���� //

void BackGround::Update()
{

}

// @brief BackGround�`�揈�� //

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