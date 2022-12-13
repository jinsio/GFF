#include "Monster.h"
#include "DxLib.h"

Monster::Monster()
    : speed(0)
    , gravity(0)
    , handle(-1)
    , hp(0)
    , alive(true)
    , dirRight(true)
{
}

Monster::~Monster()
{
    if (handle != -1)
    {
        DeleteGraph(handle);
        handle = -1;
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

void Monster::Draw()
{
    DrawRotaGraph((int)pos.x, (int)pos.y, 1.0f, 0, handle, TRUE, dirRight);
}

void Monster::CheckAlive()
{
    if (hp < 0)
    {
        alive = false;
    }
}
