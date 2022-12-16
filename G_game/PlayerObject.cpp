#include "PlayerObject.h"

PlayerObject::PlayerObject(PlayerObjectTag tag)
    :mTag(tag)
    ,mPos()
    ,mVisible(true)
    ,mAlive(true)
    ,mRightDir(true)
    ,mHandle(-1)
{
}

PlayerObject::~PlayerObject()
{
}

void PlayerObject::Draw()
{
}

