#include "ShotDummy.h"

ShotDummy::ShotDummy(class Player* player)
    :mAngle(0)
    ,AddAngle(0)
	,mRotation(0)
{
	if (mHandle = -1) {
		mHandle = LoadGraph("assets/player/player.png");
	}
}

ShotDummy::~ShotDummy()
{
}

void ShotDummy::AddRadian()
{
	mAngle += AddAngle;
		if (sinf(mAngle * 180 * DX_PI < 0 || cosf(mAngle * 180 * DX_PI < 0)))
		{
			AddAngleChange();
		}
}

void ShotDummy::AddAngleChange()
{
	AddAngle=AddAngle * -1;
}

void ShotDummy::Update(float deltaTime)
{
	AddRadian();
}

void ShotDummy::Draw()
{
	if (mAlive) {
		DrawRotaGraph((int)mPos.x, (int)mPos.y, 0.1f, mRotation, mHandle, mAlive, mRightDir);
	}
}

