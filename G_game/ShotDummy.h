#pragma once
#include "DxLib.h"
#include <vector>
#include <math.h>
#include"Player.h"
#include"PlayerObject.h"
#include"PlayerObjectManager.h"
class ShotDummy :
    public PlayerObject
{
public:
    ShotDummy(class Player* player);
    ~ShotDummy();

    void SetBulletDummyPos(VECTOR plyPos) { if (!mAlive)mPos = plyPos; }        ///�v���C���[�̒��S��e�̏����ʒu�ɑ��
    void SetBulletDummyDir(bool plyDir) { mRightDir = plyDir; }     ///�v���C���[�̌�����e�����ɑ��

    int GetRadian() { return mAngle; }
    void AddRadian();
    void AddAngleChange();

    void Update(float deltaTime)override;
    void Draw()override;

private:
    int    mAngle;
    int    AddAngle;
    int    mHandle;
    int    mRotation;
};

