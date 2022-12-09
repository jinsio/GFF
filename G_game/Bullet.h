#pragma once
// �C���N���[�h
#include "DxLib.h"
#include <vector>
#include <math.h>
#include"Player.h"
#include"PlayerObject.h"
#include"PlayerObjectManager.h"

class Bullet :public PlayerObject {

public:
    Bullet(class Player*player);
    ~Bullet();
 
    void SetBulletPos(VECTOR plyPos) { if(!mAlive)mPos = plyPos; }        ///�v���C���[�̒��S��e�̏����ʒu�ɑ��
    void SetBulletDir(bool plyDir) { mRightDir = plyDir; }     ///�v���C���[�̌�����e�����ɑ��
    
    void BulletAngleSet(float mAngle);
    void BulletMove();

    void Update(float deltaTime)override;
    void Draw()override;

    void SetonGround(bool isStand) { onGround = isStand; }
    VECTOR& GetPosition() { return mPos; }
private:
    int    mRotation;
    float  mMovePower;
    VECTOR mBulletPower;
    float  mBulletVX;
    float  mBulletVY;

    bool onGround;
};