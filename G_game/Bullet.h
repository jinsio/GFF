#pragma once
// インクルード
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
 
    void SetBulletPos(VECTOR plyPos) { if(!mAlive)mPos = plyPos; }        ///プレイヤーの中心を弾の初期位置に代入
    void SetBulletDir(bool plyDir) { mRightDir = plyDir; }     ///プレイヤーの向きを弾方向に代入
    
    void BulletAngleSet(float mAngle);                          //
    void BulletMove();

    void Update(float deltaTime)override;
    void Draw()override;

    void SetonGround(bool isStand) { onGround = isStand; }
    bool GetonGround() { return onGround; }
    /// <summary>
   /// 当たり判定座標のセッター
   /// </summary>
   /// <param name="scrPos">スクロール座標</param>
    void ScrPos(float plyspeed,float deltaTime);

    VECTOR& GetPosition() { return mPos; }
    void AddScrPos(VECTOR scrPos) { mPos = scrPos; }

private:
    int    mRotation;
    float  mMovePower;
    VECTOR mBulletPower;
    float  mBulletVX;
    float  mBulletVY;

    class  Scroll;

    VECTOR bulletPos;
    bool onGround;
};