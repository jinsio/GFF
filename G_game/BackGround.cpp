#include "BackGround.h"

// @brief BackGround�̃R���X�g���N�^�[ //

BackGround::BackGround()
    :bgPos()
    ,drawBgX(0)
    ,drawBgY(0)
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

// @brief BackGround�`�揈�� //

void BackGround::Draw(int scrX,int scrY)
{
    //---�X�N���[�����W���f---//
    drawBgX = bgPos.x - scrX;
    drawBgY = bgPos.y - scrY;

    //---�w�ʃ��C���[�`��---//
    DrawGraph(drawBgX % ScreenW, drawBgY, bgBack, TRUE);
    DrawGraph(drawBgX % ScreenW + ScreenW, drawBgY, bgBack, TRUE);
    
    //---�������C���[�`��---//
    DrawGraph(drawBgX * 2 % ScreenW, drawBgY, bgMid, TRUE);
    DrawGraph(drawBgX * 2 % ScreenW + ScreenW, drawBgY, bgMid, TRUE);
    
    //---�O�ʃ��C���[�`��---//
    DrawGraph(drawBgX * 3 % ScreenW, drawBgY, bgFront, TRUE);
    DrawGraph(drawBgX * 3 % ScreenW + ScreenW, drawBgY, bgFront, TRUE);
}