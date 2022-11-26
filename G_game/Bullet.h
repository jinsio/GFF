#pragma once
// �C���N���[�h
#include "DxLib.h"
#include <vector>
#include <math.h>
#include"PlayerObject.h"

class Bullet :public PlayerObject {

public:
    Bullet();
    ~Bullet();
 
    void SetBulletPos(VECTOR plyPos) { if(!mAlive)mPos = plyPos; }        ///�v���C���[�̒��S��e�̏����ʒu�ɑ��
    void SetBulletDir(bool plyDir) { mRightDir = plyDir; }     ///�v���C���[�̌�����e�����ɑ��

    void Shot();
    void BulletMove();
    void Update(float deltaTime)override;
    void Draw();

protected:
    VECTOR mmMovePower;
    int    mRotation;
    float  mMovePower;

};