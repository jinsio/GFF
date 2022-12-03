#include "Bullet.h"

Bullet::Bullet(class Player*player)
    :PlayerObject(),
    mRotation(0),
    mMovePower(10),
    mBulletVX(0),
    mBulletVY(0),
    mBulletPower{0,0}
{
    if (mHandle = -1) {
        mHandle = LoadGraph("assets/player/player.png");
    }
    mPos = player->GetPos();
}

Bullet::~Bullet()
{
}



void Bullet::BulletAngleSet(float mAngle)
{

    mBulletVX = mMovePower * cosf(mAngle* DX_PI);
    mBulletVY = -mMovePower * sinf(mAngle* DX_PI);

    mBulletPower.x = mBulletVX;
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
    mPos = VAdd(mPos, mBulletPower);
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
