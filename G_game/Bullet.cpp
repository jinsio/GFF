#include "Bullet.h"

Scroll* scroll;

Bullet::Bullet(class Player*player)
    :PlayerObject(),
    mRotation(0),
    mMovePower(5),
    mBulletVX(0),
    mBulletVY(0),
    mBulletPower{0,0},
    bulletPos{}
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

void Bullet::LEFTScrPos(float plyspeed,float deltaTime)
{
    if (GetonGround() && (CheckHitKey(KEY_INPUT_RIGHT)))
    {
        mPos.x -= plyspeed* deltaTime/10;
    }
}

void Bullet::RIGHTScrPos(float plyspeed, float deltaTime)
{
     if (GetonGround() && (CheckHitKey(KEY_INPUT_LEFT)))
    {
        mPos.x += plyspeed * deltaTime / 10;
    }
}

