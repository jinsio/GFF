#include "TimeManager.h"
#include "DxLib.h"

TimeManager::TimeManager()
    : deltaTime(0)
    , prevTime(0)
    , nowTime(0)
{
}

TimeManager::~TimeManager()
{
}

void TimeManager::Update()
{
    nowTime = GetNowCount();
    deltaTime = (nowTime-prevTime)/1000.0f;
}
