#include "BackGround.h"

// @brief BackGround�̃R���X�g���N�^�[ //

BackGround::BackGround()
    :bgScreenX(0)
{
    first[0].bgHandle = LoadGraph("assets/BackGround/R2_distantView.png");    //�w�ʃ��C���[
    first[1].bgHandle = LoadGraph("assets/BackGround/R2_middleView.png");     //�������C���[
    first[2].bgHandle = LoadGraph("assets/BackGround/R2_foreGround.png");     //�O�ʃ��C���[
}

// @brief BackGround�̃f�X�g���N�^�\ //

BackGround::~BackGround()
{
    for (int i = 0; i < LayerNum; i++)          //���C���[�̖�����for������
    {
        if (first[i].bgHandle != -1)                  //���g�������Ă�����
        {
            DeleteGraph(first[i].bgHandle);           //��ɂ���
        }
    }
}

// @brief BackGround�X�V���� //

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

// @brief BackGround�`�揈�� //

void BackGround::Draw()
{

    for (int i = 0; i < LayerNum; i++)
    {  
        DrawGraph(first[i].bgX, first[i].bgY, first[i].bgHandle, TRUE);
    }
}