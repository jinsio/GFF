#pragma once
// インクルード
#include "DxLib.h"
#include <vector>
#include <math.h>
#include "Player.h"
#include "GameObject.h"
#include "GameObjectManager.h"
#include "Scroll.h"


class Bullet :public GameObject {

public:
    Bullet(class Player*player);
    ~Bullet();
 
    void SetBulletPos(VECTOR plyPos) { if(!mAlive)mPos = plyPos; }        ///プレイヤーの中心を弾の初期位置に代入
    void SetBulletDir(bool plyDir) { mRightDir = plyDir; }     ///プレイヤーの向きを弾方向に代入
    
    void BulletAngleSet(double mAngle);                          //弾の角度をダミーから持ってくる
    void BulletMove();                                          //弾の動き

    void Update(float deltaTime)override;                       //更新
    void Draw(int offSetX,int offSetY)override;                                        //描画

    void SetonGround(bool isStand) { onGround = isStand; }      //着地しているか
    bool GetonGround() { return onGround; }                     //着地しているかを持ってくる

    void BulletNumberAdd(int ButtonStatus);                                     //弾数追加

    VECTOR& GetPosition() { return mPos; }                              //弾の位置を持ってくる

private:
    int     mRotation;                       //回転角
    float   mMovePower;                      //弾の発射の力
    VECTOR  mBulletPower;                    //弾の方向
    double  mBulletVX;                      //弾のX方向の力
    double  mBulletVY;                      //弾のY方向の力
    int     mBulletNumber;                  //弾数

    class  Scroll;

    VECTOR bulletPos;
    bool onGround;
};