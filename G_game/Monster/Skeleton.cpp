#include "Skeleton.h"
#include "monsterInfo.h"

/**
* �X�P���g���̃R���X�g���N�^
*/
Skeleton::Skeleton()
{
    scale.x = monsterScaleS.x;
    scale.y = monsterScaleM.y;
    halfScale.x = scale.x / 2;
    halfScale.y = scale.y / 2;
}

/**
* �X�P���g���̃f�X�g���N�^
*/
Skeleton::~Skeleton()
{
}

/**
* �X�P���g���̍X�V
* 
* @param[in] deltaTime 1�t���[���̌o�ߎ���
*/
void Skeleton::Update(float deltaTime)
{
}
