#pragma once
// �C���N���[�h
#include "DxLib.h"
#include <vector>
#include <math.h>
#include "Player.h"
#include"PlayerObject.h"
#include"PlayerObjectManager.h"
#include "Scroll.h"


class Bullet :public PlayerObject {

public:
    Bullet(class Player*player);
    ~Bullet();
 
    void SetBulletPos(VECTOR plyPos) { if(!mAlive)mPos = plyPos; }        ///�v���C���[�̒��S��e�̏����ʒu�ɑ��
    void SetBulletDir(bool plyDir) { mRightDir = plyDir; }     ///�v���C���[�̌�����e�����ɑ��
    
    void BulletAngleSet(float mAngle);                          //�e�̊p�x���_�~�[���玝���Ă���
    void BulletMove();                                          //�e�̓���

    void Update(float deltaTime)override;                       //�X�V
    void Draw()override;                                        //�`��

    void SetonGround(bool isStand) { onGround = isStand; }      //���n���Ă��邩
    bool GetonGround() { return onGround; }                     //���n���Ă��邩�������Ă���
 /*   /// <summary>
   /// �����蔻����W�̃Z�b�^�[
   /// </summary>
   /// <param name="scrPos">�X�N���[�����W</param>
    void LEFTScrPos(float plyspeed,float deltaTime);
    void RIGHTScrPos(float plyspeed, float deltaTime);*/

    void GetScr(int scrX, int scrY) { offSetX = scrX; offSetY = scrY; } //�X�N���[���ʂ������Ă���

    VECTOR& GetPosition() { return mPos; }                              //�e�̈ʒu�������Ă���

private:
    int    mRotation;                       //��]�p
    float  mMovePower;                      //�e�̔��˂̗�
    VECTOR mBulletPower;                    //�e�̕���
    float  mBulletVX;                       //�e��X�����̗�
    float  mBulletVY;                       //�e��Y�����̗�

    //�X�N���[������
    int offSetX;
    int offSetY;

    class  Scroll;

    VECTOR bulletPos;
    bool onGround;
};