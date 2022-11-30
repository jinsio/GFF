#include "Bullet.h"
Bullet::Bullet(class Player*player)
    :mRotation(),
    mMovePower(10),
    mAngle(90),
    mRightMovePower(),
    mLeftMovePower(),
    mBulletVX(0),
    mBulletVY(0),
    mBulletPower()
{
    if (mHandle = -1) {
        mHandle = LoadGraph("assets/player/player.png");
    }
    mRightDir = player->GetDir();
    mPos = player->GetPos();
    BulletAngelSet();
}

Bullet::~Bullet()
{
}

void Bullet::BulletAngelSet()
{
    const float PI = 3.14;

    mBulletVX = mMovePower * cosf(mAngle * PI * 2);
    mBulletVY = mMovePower * sinf(mAngle * PI * 2);

    mBulletPower.y = mBulletVY;
    
    if (mRightDir)
    {
        mBulletPower.x = -mBulletVX;
    }
    if (!mRightDir)
    {
        mBulletPower.x = mBulletVX;
    }
}

void Bullet::BulletMove()
{
    if (mRightDir)
    {
        mPos=VAdd(mPos,mBulletPower);
    }
    if (!mRightDir)
    {
        mPos=VAdd(mPos,mBulletPower);
    }

    mBulletPower.y += 0.2 ;
}

void Bullet::Update(float deltaTime)
{   
        if (mAlive) {
            BulletMove();
        }
}

void Bullet::Draw()
{
    if (mAlive) {
        DrawRotaGraph((int)mPos.x, (int)mPos.y, 0.1f, mRotation, mHandle, mAlive, mRightDir);
    }
    mRotation++;
}
