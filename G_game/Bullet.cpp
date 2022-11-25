#include "Bullet.h"

Bullet::Bullet()
: mPos(),
  mDir(),
  mAlive(FALSE),
  mHandle(),
  mRotation(),
  mMovePower(),
  mmMovePower()
{
    mHandle = LoadGraph("assets/player/player.png");
}

Bullet::~Bullet()
{
}

void Bullet::Shot(VECTOR PlyPos, bool mDir)
{
    mPos = PlyPos;
    mAlive = TRUE;  
}

void Bullet::BulletMove(VECTOR PlyPos, bool mDir)
{
    if (mDir)
    {
        mPos.x -= 2.0f;

    }
    if (!mDir)
    {
        mPos.x += 2.0f;
    }
}

void Bullet::Update(VECTOR PlyPos, bool PlyDir)
{   
    if (CheckHitKey(KEY_INPUT_S)) {
        mDir = PlyDir;
        Shot(PlyPos, mDir);
    }
        BulletMove(PlyPos, mDir);
}

void Bullet::Draw()
{
    if (mAlive) {
        DrawRotaGraph((int)mPos.x, (int)mPos.y, 0.1f, mRotation, mHandle, mAlive, mDir);
    }
    mRotation++;
}
