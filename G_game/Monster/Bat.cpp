#include "Bat.h"
#include "monsterInfo.h"

/**
* �R�E�����̃R���X�g���N�^
*/
Bat::Bat()
{
    scale.x = monsterScaleS.x;
    scale.y = monsterScaleS.y;
    halfScale.x = scale.x / 2;
    halfScale.y = scale.y / 2;
}

/**
* �R�E�����̃f�X�g���N�^
*/
Bat::~Bat()
{
}

/**
* �R�E�����̍X�V
* 
* @param[in] deltaTime 1�t���[���̌o�ߎ���
*/
void Bat::Update(float deltaTime)
{
}

