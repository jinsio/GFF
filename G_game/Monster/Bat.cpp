#include "Bat.h"
#include "monsterInfo.h"

/**
* コウモリのコンストラクタ
*/
Bat::Bat()
{
    scale.x = monsterScaleS.x;
    scale.y = monsterScaleS.y;
    halfScale.x = scale.x / 2;
    halfScale.y = scale.y / 2;
}

/**
* コウモリのデストラクタ
*/
Bat::~Bat()
{
}

/**
* コウモリの更新
* 
* @param[in] deltaTime 1フレームの経過時間
*/
void Bat::Update(float deltaTime)
{
}

