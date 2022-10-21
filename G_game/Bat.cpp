#include "Bat.h"
#include "monsterInfo.h"

Bat::Bat()
{
    scale.x = monsterScaleS.x;
    scale.y = monsterScaleS.y;
    halfScale.x = scale.x / 2;
    halfScale.y = scale.y / 2;
}

Bat::~Bat()
{
}
