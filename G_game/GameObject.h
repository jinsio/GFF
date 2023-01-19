#pragma once
#include "Dxlib.h"
#include <math.h>
#include "GameObjectTag.h"

class GameObject
{
public:
    GameObject(GameObjectTag tag);
    virtual ~GameObject();

    VECTOR  GetPos() { return mPos; }
    void    SetPos(VECTOR Pos) { mPos = Pos; }

    bool    GetAlive() { return mAlive; }
    void    SetAlive(bool SetAlive) { mAlive = SetAlive; }

    GameObjectTag     GetTag()const { return mTag; }                           // ゲームオブジェクトの種類取得

    virtual void Update(float deltaTime) = 0;
    virtual void Draw(int offSetX, int offSetY);


protected:
    GameObjectTag   mTag;
    VECTOR  mPos;
    bool    mAlive;
    bool    mRightDir;
    int     mHandle;

};

