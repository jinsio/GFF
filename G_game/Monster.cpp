#include "Monster.h"
#include "DxLib.h"
#include "GameObjectTag.h"

Monster::Monster()
    : GameObject(GameObjectTag::Enemy)
    , speed(0)
    , state(IDLE)
    , hp(0)
{
}

Monster::~Monster()
{
    if (mHandle != -1)
    {
        DeleteGraph(mHandle);
        mHandle = -1;
    }
    for (auto handle : moveAnim)
    {
        if (handle != -1)
        {
            DeleteGraph(handle);
            handle = -1;
        }
    }
    for (auto handle : attackAnim)
    {
        if (handle != -1)
        {
            DeleteGraph(handle);
            handle = -1;
        }
    }
    for (auto handle : damageAnim)
    {
        if (handle != -1)
        {
            DeleteGraph(handle);
            handle = -1;
        }
    }
}

void Monster::CheckAlive()
{
    if (hp < 0)
    {
        state = DEAD;
    }
}
