#pragma once
#include "DxLib.h"
#include <math.h>

class PlayerObject
{
public:
    PlayerObject();
    virtual ~PlayerObject();

    VECTOR  GetPos() { return mPos; }
    void    SetPos(VECTOR Pos) { mPos = Pos; }

    bool    GetAlive() { return mAlive; }
    void    SetAlive(bool SetAlive) { mAlive = SetAlive; }

    virtual void Update(float deltaTime) = 0;
    virtual void Draw();

protected:
    VECTOR  mPos;
    bool    mAlive;
    bool    mRightDir;
    int     mHandle;
 
};

