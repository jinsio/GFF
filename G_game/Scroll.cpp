#include "Scroll.h"

// @brief Scroll�R���X�g���N�^�\ //

Scroll::Scroll()
	:scrRX(750)
	,scrRY(450)
	,scrLX(530)
	,scrLY(190)
	,scrPos()
{
}

// @brief Scroll�f�X�g���N�^�[ //

Scroll::~Scroll()
{
}

// @brief Scroll�ړ����� //

void Scroll::MoveScroll(VECTOR& plyPos)
{
	if (plyPos.x > scrRX&&scrPos.x>=-scrMaxW)		//�v���C���[���X�N���[������ʒu�܂ŗ�����
	{
		plyPos.x = scrRX;							//�v���C���[���̈ʒu�͌Œ�
		scrPos.x -= scrSpeedLR;						//�w�i���W���X�N���[��
	}
	if (plyPos.y > scrRY&&scrPos.y>=-scrMaxH)
	{
		plyPos.y = scrRY;
		scrPos.y -= scrSpeedXY;
	}
	if (plyPos.x < scrLX && scrPos.x <= scrMinW)
	{
		plyPos.x = scrLX;
		scrPos.x += scrSpeedLR;
	}
	if (plyPos.y < scrLY && scrPos.y <= scrMinH)
	{
		plyPos.y = scrLY;
		scrPos.y -= scrSpeedXY;
	}
}