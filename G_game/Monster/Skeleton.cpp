#include "Skeleton.h"
#include "monsterInfo.h"

/**
* スケルトンのコンストラクタ
*/
Skeleton::Skeleton()
{
    scale.x = monsterScaleS.x;
    scale.y = monsterScaleM.y;
    halfScale.x = scale.x / 2;
    halfScale.y = scale.y / 2;
}

/**
* スケルトンのデストラクタ
*/
Skeleton::~Skeleton()
{
}

/**
* スケルトンの更新
* 
* @param[in] deltaTime 1フレームの経過時間
*/
void Skeleton::Update(float deltaTime)
{
}
