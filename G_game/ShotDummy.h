#pragma once
#include "DxLib.h"
#include <vector>
#include <math.h>
#include"Player.h"
#include"GameObject.h"
#include"GameObjectManager.h"
class ShotDummy :
    public GameObject
{
public:
    ShotDummy(class Player* player);
    ~ShotDummy();

    void SetBulletDummyPos(VECTOR plyPos) { if (!mAlive)mPos = plyPos; }        ///�v���C���[�̒��S��e�̏����ʒu�ɑ��

    bool GetBulletDummyDir() { return mRightDir; }
    void SetBulletDummyDir(bool plyDir) { mRightDir = plyDir; }     ///�v���C���[�̌�����e�����ɑ��

    double GetRadian() { return mAngle; }
    void  AddRadian(float _deltaTime);
    void  AddAngleChange();

    void Update(float deltaTime)override;
    void Draw(int offSetX, int offSetY)override;

private:
    double   mAngle;
    double   AddAngle;
    int     mHandle;
    float   mRotation;
};

