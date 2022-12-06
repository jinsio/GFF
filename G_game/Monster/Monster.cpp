#include "Monster.h"
#include "DxLib.h"

/**
* �R���X�g���N�^
*/
Monster::Monster()
    : speed(0)
    , gravity(0)
    , displayImage(-1)
    , hp(0)
    , isAlive(true)
    , isAlly(false)
    , isDirRight(true)
{
}

/**
* ���z�f�X�g���N�^
*/
Monster::~Monster()
{
    if (displayImage != -1)
    {
        DeleteGraph(displayImage);
        displayImage = -1;
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

/**
* �`��
*/
void Monster::Draw()
{
    DrawRotaGraph((int)pos.x, (int)pos.y, 1.0f, 0, displayImage, TRUE, isDirRight);
}
