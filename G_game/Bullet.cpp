#include "Bullet.h"

Bullet::Bullet()
    :mRotation(),
    mMovePower(),
    mmMovePower()
{
    if (mHandle = -1) {
        mHandle = LoadGraph("assets/player/player.png");
    }
}

Bullet::~Bullet()
{
}

void Bullet::Shot()
{
    mAlive = TRUE;  

    /*Bullet* bulletArray[5] = { nullptr };
    for (int i = 0; i < 5; i++) {
        if (bulletArray[i] == nullptr) {
            bulletArray[i] = new Bullet();
            break;
        }
    }*/
}

void Bullet::BulletMove()
{
    if (mRightDir)
    {
        mPos.x -= 2.0f;

    }
    if (!mRightDir)
    {
        mPos.x += 2.0f;
    }
}

void Bullet::Update(float deltaTime)
{   
    if (CheckHitKey(KEY_INPUT_S)) {
        Shot();
    }
        BulletMove();
}

void Bullet::Draw()
{
    if (mAlive) {
        DrawRotaGraph((int)mPos.x, (int)mPos.y, 0.1f, mRotation, mHandle, mAlive, mRightDir);
    }
    mRotation++;
}
