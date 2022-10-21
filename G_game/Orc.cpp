#include "Orc.h"
#include "monsterInfo.h"

Orc::Orc()
{
    scale.x = monsterScaleM.x;
    scale.y = monsterScaleM.y;
    halfScale.x = scale.x / 2;
    halfScale.y = scale.y / 2;
}

Orc::~Orc()
{
}
