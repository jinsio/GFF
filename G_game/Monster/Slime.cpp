#include "Slime.h"
#include "monsterInfo.h"
#include "DxLib.h"

/**
* スライムのコンストラクタ
*/
Slime::Slime()
{
    scale.x = monsterScaleS.x;
    scale.y = monsterScaleS.y;
    halfScale.x = scale.x / 2;
    halfScale.y = scale.y / 2;
}


/**
* スライムのデストラクタ
*/
Slime::~Slime()
{
}

/**
* スライムの更新
* 
* @param[in] deltaTime 1フレームの経過時間
*/
void Slime::Update(float deltaTime)
{
}
