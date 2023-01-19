#include "GameObject.h"
GameObject::GameObject(GameObjectTag tag)
    : mTag(tag)
    , mPos()
    , mAlive(true)
    , mRightDir(true)
    , mHandle(-1)
{
}

GameObject::~GameObject()
{
}

void GameObject::Draw(int offSetX, int offSetY)
{

}
