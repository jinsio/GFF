#include "ShotDummy.h"

ShotDummy::ShotDummy(class Player* player)
    :GameObject(GameObjectTag::ShotDummy)
	,mAngle(0)
    ,AddAngle(0.3)
	,mRotation(0)
{
	if (mHandle = -1) {
		mHandle = LoadGraph("assets/player/arrow.png");
	}
	mRightDir = player->GetDir();
	mPos = player->GetPos();
}

ShotDummy::~ShotDummy()
{
}

void ShotDummy::AddRadian(float _deltaTime)
{
		if (mAngle < 0 )
		{
			mAngle = 0.01;
			AddAngleChange();
		}
		else if (mAngle > 0.5)
		{
			mAngle = 0.49;
			AddAngleChange();
		}
		mAngle += AddAngle*_deltaTime;
}

void ShotDummy::AddAngleChange()
{
	AddAngle=AddAngle * -1;
}

void ShotDummy::Update(float deltaTime)
{

}

void ShotDummy::Draw(int offSetX, int offSetY)
{
	if (mAlive&& mRightDir) {
		DrawRotaGraph((int)mPos.x- offSetX, (int)mPos.y - offSetY, 1, mAngle*DX_PI, mHandle, mAlive, mRightDir);
	}
	else if (mAlive && !mRightDir)
	{
		DrawRotaGraph((int)mPos.x- offSetX , (int)mPos.y - offSetY, 1, -mAngle * DX_PI, mHandle, mAlive, mRightDir);
	}
	/*unsigned int Color;

	Color = GetColor(255, 255, 255);
	DrawFormatString(0, 0, Color, "ïœêî i ÇÃílÇÕ %f Ç≈Ç∑", mAngle);*/
}

