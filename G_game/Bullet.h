#pragma once
// インクルード
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
 
    void SetBulletPos(VECTOR plyPos) { if(!mAlive)mPos = plyPos; }        ///プレイヤーの中心を弾の初期位置に代入
    void SetBulletDir(bool plyDir) { mRightDir = plyDir; }     ///プレイヤーの向きを弾方向に代入
    
    void BulletAngelSet();
    void BulletMove();
    
    void Update(float deltaTime)override;
    void Draw()override;

protected:
    VECTOR mLeftMovePower;
    VECTOR mRightMovePower;
    int    mRotation;
    float  mMovePower;
    float  mAngle;
    VECTOR mBulletPower;
    float  mBulletVX;
    float  mBulletVY;

};