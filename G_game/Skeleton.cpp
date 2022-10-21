#include "Skeleton.h"
#include "monsterInfo.h"

Skeleton::Skeleton()
{
    scale.x = monsterScaleS.x;
    scale.y = monsterScaleM.y;
    halfScale.x = scale.x / 2;
    halfScale.y = scale.y / 2;
}

Skeleton::~Skeleton()
{
}
