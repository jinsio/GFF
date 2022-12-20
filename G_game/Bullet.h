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
    
    void BulletAngleSet(double mAngle);                          //�e�̊p�x���_�~�[���玝���Ă���
    void BulletMove();                                          //�e�̓���

    void Update(float deltaTime)override;                       //�X�V
    void Draw(int offSetX,int offSetY)override;                                        //�`��

    void SetonGround(bool isStand) { onGround = isStand; }      //���n���Ă��邩
    bool GetonGround() { return onGround; }                     //���n���Ă��邩�������Ă���

    void BulletNumberAdd(int ButtonStatus);                                     //�e���ǉ�

    VECTOR& GetPosition() { return mPos; }                              //�e�̈ʒu�������Ă���

private:
    int     mRotation;                       //��]�p
    float   mMovePower;                      //�e�̔��˂̗�
    VECTOR  mBulletPower;                    //�e�̕���
    double  mBulletVX;                      //�e��X�����̗�
    double  mBulletVY;                      //�e��Y�����̗�
    int     mBulletNumber;                  //�e��

    class  Scroll;

    VECTOR bulletPos;
    bool onGround;
};