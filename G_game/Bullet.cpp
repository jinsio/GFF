#include "Bullet.h"
#include "PlayScene.h"
Scroll* scroll;

Bullet::Bullet(class Player*player)
    :GameObject(GameObjectTag::Bullet),
    mRotation(0),
    mMovePower(5),
    mBulletVX(0),
    mBulletVY(0),
    mBulletPower{0,0},
    bulletPos{},
    mBulletNumber(0)
{
    if (mHandle = -1) {
        mHandle = LoadGraph("assets/player/player.png");
    }
    mPos.x= player->GetPos().x;
    mPos.y = player->GetPos().y + -10;
}

Bullet::~Bullet()
{
}



void Bullet::BulletAngleSet(double mAngle)
{

    mBulletVX = mMovePower * cosf(mAngle* DX_PI);
    mBulletVY = -mMovePower * sinf(mAngle* DX_PI);

    mBulletPower.x = (float)mBulletVX ;
    mBulletPower.y = (float)mBulletVY ;
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
    if (onGround)
    {
        mBulletPower.x = 0;
        mBulletPower.y = 0;
    }
    else
    {
        if (mRightDir)
        {
            mPos = VAdd(mPos, mBulletPower);
        }
        if (!mRightDir)
        {
            mPos = VAdd(mPos, mBulletPower);
        }
        mPos = VAdd(mPos, mBulletPower);
        mBulletPower.y += 0.2f;
    }
}


void Bullet::Update(float deltaTime)
{
        BulletMove();
}

void Bullet::Draw(int offSetX,int offSetY)
{
    DrawRotaGraph((int)mPos.x - offSetX, (int)mPos.y - offSetY, 0.1f, mRotation, mHandle, mAlive, mRightDir);
    mRotation++;
}

void Bullet::BulletNumberAdd(int ButtonStatus)
{
    if (ButtonStatus==3)
    {
        mBulletNumber++;
    }
}
