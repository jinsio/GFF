#include "Slime.h"
#include "monsterInfo.h"

Slime::Slime()
{
    scale.x = monsterScaleS.x;
    scale.y = monsterScaleS.y;
    halfScale.x = scale.x / 2;
    halfScale.y = scale.y / 2;
}

Slime::~Slime()
{
}
