#include "BaseMonster.h"
#include "DxLib.h"

//------------------------------------------------------------------------------------------------//
// @brief BaseMonster�̃R���X�g���N�^
//------------------------------------------------------------------------------------------------//
BaseMonster::BaseMonster()
    : speed(0)
    , gravity(0)
    , displayImage(-1)
    , hp(0)
    , isAlive(true)
    , isAlly(false)
    , isDirRight(true)
{
}

//------------------------------------------------------------------------------------------------//
// @brief BaseMonster�̃f�X�g���N�^
//------------------------------------------------------------------------------------------------//
BaseMonster::~BaseMonster()
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

//------------------------------------------------------------------------------------------------//
// @brief BaseMonster�̕`�揈��
//------------------------------------------------------------------------------------------------//
void BaseMonster::Draw()
{
    DrawRotaGraph((int)pos.x, (int)pos.y, 1.0f, 0, displayImage, TRUE, isDirRight);
}
