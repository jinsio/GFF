#pragma once
// インクルード
#include "DxLib.h"
#include <vector>
#include <math.h>

class Bullet {

public:
    Bullet();
    ~Bullet();
    void Shot(VECTOR PlyPos, bool PlyDir);
    void BulletMove(VECTOR PlyPos, bool PlyDir);
    void Update(VECTOR PlyPos,bool PlyDir);
    void Draw();

protected:
    VECTOR mPos;
    VECTOR mmMovePower;
    bool   mDir;
    bool   mAlive;
    int    mHandle;
    int    mRotation;
    float  mMovePower;

};