#include "Slime.h"
#include "monsterInfo.h"
#include "DxLib.h"

/**
* �X���C���̃R���X�g���N�^
*/
Slime::Slime()
{
    scale.x = monsterScaleS.x;
    scale.y = monsterScaleS.y;
    halfScale.x = scale.x / 2;
    halfScale.y = scale.y / 2;
}


/**
* �X���C���̃f�X�g���N�^
*/
Slime::~Slime()
{
}

/**
* �X���C���̍X�V
* 
* @param[in] deltaTime 1�t���[���̌o�ߎ���
*/
void Slime::Update(float deltaTime)
{
}
