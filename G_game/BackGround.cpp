#include "BackGround.h"

// @brief BackGround�̃R���X�g���N�^�[ //

BackGround::BackGround()
    :bgScreenX(0)
{
    first.bgHandle[0] = LoadGraph("assets/BackGround/R2_distantView.png");    //�w�ʃ��C���[
    first.bgHandle[1] = LoadGraph("assets/BackGround/R2_middleView.png");     //�������C���[
    first.bgHandle[2] = LoadGraph("assets/BackGround/R2_foreGround.png");     //�O�ʃ��C���[
}

// @brief BackGround�̃f�X�g���N�^�\ //

BackGround::~BackGround()
{
    for (int i = 0; i < LayerNum; i++)          //���C���[�̖�����for������
    {
        if (first.bgHandle[i] != -1)                  //���g�������Ă�����
        {
            DeleteGraph(first.bgHandle[i]);           //��ɂ���
        }
    }
}

// @brief BackGround�X�V���� //

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

// @brief BackGround�`�揈�� //

void BackGround::Draw()
{

    for (int i = 0; i < LayerNum; i++)
    {  
        DrawGraph(first.screenPos[i] % 1920, first.bgY[i], first.bgHandle[i], TRUE);
        DrawGraph(second.screenPos[i] % 1920 + 1920, first.bgY[i], first.bgHandle[i], TRUE);
    }
}