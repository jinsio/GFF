#include "BackGround.h"

// @brief BackGround�̃R���X�g���N�^�[ //

BackGround::BackGround()
    :bgHandle{-1,-1,-1}
    ,bgX{0,0,0}
    ,bgY{0,0,0}
    ,bgScreenX(0)
{
    bgHandle[0] = LoadGraph("assets/BackGround/R2_distantView.png");    //�w�ʃ��C���[
    bgHandle[1] = LoadGraph("assets/BackGround/R2_middleView.png");     //�������C���[
    bgHandle[2] = LoadGraph("assets/BackGround/R2_foreGround.png");     //�O�ʃ��C���[
}

// @brief BackGround�̃f�X�g���N�^�\ //

BackGround::~BackGround()
{
    for (int i = 0; i < LayerNum; i++)          //���C���[�̖�����for������
    {
        if (bgHandle[i] != -1)                  //���g�������Ă�����
        {
            DeleteGraph(bgHandle[i]);           //��ɂ���
        }
    }
}

// @brief BackGround�X�V���� //

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

// @brief BackGround�`�揈�� //

void BackGround::Draw()
{

    for (int i = 0; i < LayerNum; i++)
    {
        bgX[i] = bgPos.x * (1.5f * i) ;
        bgY[i] = bgPos.y;
        DrawGraph(bgX[i], bgY[i], bgHandle[i], TRUE);
    }
}