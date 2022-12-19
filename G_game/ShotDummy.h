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

    void SetBulletDummyPos(VECTOR plyPos) { if (!mAlive)mPos = plyPos; }        ///プレイヤーの中心を弾の初期位置に代入

    bool GetBulletDummyDir() { return mRightDir; }
    void SetBulletDummyDir(bool plyDir) { mRightDir = plyDir; }     ///プレイヤーの向きを弾方向に代入

    float GetRadian() { return mAngle; }
    void  AddRadian(float _deltaTime);
    void  AddAngleChange();

    void GetScr(int scrX, int scrY) { offSetX = scrX; offSetY = scrY; } //スクロール量を持ってくる

    void Update(float deltaTime)override;
    void Draw()override;

private:
    float   mAngle;
    float   AddAngle;
    int     mHandle;
    float   mRotation;
    int     offSetX;
    int     offSetY;
};

