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
    
    void BulletAngleSet(float mAngle);                          //弾の角度をダミーから持ってくる
    void BulletMove();                                          //弾の動き

    void Update(float deltaTime)override;                       //更新
    void Draw()override;                                        //描画

    void SetonGround(bool isStand) { onGround = isStand; }      //着地しているか
    bool GetonGround() { return onGround; }                     //着地しているかを持ってくる
 /*   /// <summary>
   /// 当たり判定座標のセッター
   /// </summary>
   /// <param name="scrPos">スクロール座標</param>
    void LEFTScrPos(float plyspeed,float deltaTime);
    void RIGHTScrPos(float plyspeed, float deltaTime);*/

    void GetScr(int scrX, int scrY) { offSetX = scrX; offSetY = scrY; } //スクロール量を持ってくる

    VECTOR& GetPosition() { return mPos; }                              //弾の位置を持ってくる

private:
    int    mRotation;                       //回転角
    float  mMovePower;                      //弾の発射の力
    VECTOR mBulletPower;                    //弾の方向
    float  mBulletVX;                       //弾のX方向の力
    float  mBulletVY;                       //弾のY方向の力

    //スクロール差分
    int offSetX;
    int offSetY;

    class  Scroll;

    VECTOR bulletPos;
    bool onGround;
};