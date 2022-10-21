#include "BaseMonster.h"
#include "DxLib.h"

//------------------------------------------------------------------------------------------------//
// @brief BaseMonsterのコンストラクタ
//------------------------------------------------------------------------------------------------//
BaseMonster::BaseMonster()
{
    pos.x = 0;
    pos.y = 0;
    scale.x = 64;
    scale.y = 64;
    halfScale.x = scale.x / 2;
    halfScale.y = scale.y / 2;
    displayImage = -1;
    hp = 0;
    isAlive = true;
    isAlly = false;
    isDirRight = true;
}

//------------------------------------------------------------------------------------------------//
// @brief BaseMonsterのデストラクタ
//------------------------------------------------------------------------------------------------//
BaseMonster::~BaseMonster()
{
    if (displayImage != -1)
    {
        DeleteGraph(displayImage);
        displayImage = -1;
    }
    for (i = 0; i < moveAnimNum; i++)
    {
        if (moveAnim[i] != -1)
        {
            DeleteGraph(moveAnim[i]);
            moveAnim[i] = -1;
        }
    }
    for (i = 0; i < attackAnimNum; i++)
    {
        if (attackAnim[i] != -1)
        {
            DeleteGraph(attackAnim[i]);
            attackAnim[i] = -1;
        }
    }
    for (i = 0; i < damageAnimNum; i++)
    {
        if (damageAnim[i] != -1)
        {
            DeleteGraph(damageAnim[i]);
            damageAnim[i] = -1;
        }
    }
}

//------------------------------------------------------------------------------------------------//
// @brief BaseMonsterの描画処理
//------------------------------------------------------------------------------------------------//
void BaseMonster::Draw()
{
    DrawRotaGraph((int)pos.x, (int)pos.y, 1.0f, 0, displayImage, TRUE, isDirRight);
}
