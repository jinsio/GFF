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

    bool GetBulletDummyDir() { return mRightDir; }
    void SetBulletDummyDir(bool plyDir) { mRightDir = plyDir; }     ///�v���C���[�̌�����e�����ɑ��


    void SetEntryFlag() { mEntryFlag=true; }
    bool GetEntryFlag() { return mEntryFlag; }

    float GetRadian() { return mAngle; }
    void  AddRadian(float _deltaTime);
    void  AddAngleChange();

    void Update(float deltaTime)override;
    void Draw()override;

private:
    float  mAngle;
    float  AddAngle;
    int    mHandle;
    float    mRotation;
    bool   mEntryFlag;
};

