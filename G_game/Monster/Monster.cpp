#include "Monster.h"
#include "DxLib.h"

/**
* コンストラクタ
*/
Monster::Monster()
    : speed(0)
    , gravity(0)
    , handle(-1)
    , hp(0)
    , isAlive(true)
    , isAlly(false)
    , isDirRight(true)
{
}

/**
* 仮想デストラクタ
*/
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

void Monster::Update(float deltaTime)
{
}

/**
* 描画
*/
void Monster::Draw()
{
    DrawRotaGraph((int)pos.x, (int)pos.y, 1.0f, 0, handle, TRUE, isDirRight);
}
