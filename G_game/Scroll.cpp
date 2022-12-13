#include "Scroll.h"
#include "Bullet.h"
// @brief Scroll�R���X�g���N�^�\ //

Bullet* bullet;

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

void Scroll::MoveScroll(float deltaTime,VECTOR& plyPos)
{
	if (plyPos.x > scrRX && scrPos.x >= -scrMaxW)		//�v���C���[���X�N���[������ʒu�܂ŗ�����
	{
		plyPos.x = scrRX;							//�v���C���[�̈ʒu�͌Œ�
		scrPos.x -= scrSpeedLR * deltaTime / 10;						//�w�i���W���X�N���[��
		/*if (bullet != nullptr) {
			bullet->AddScrPos(scrPos.x);
		}*/
	}
	if (plyPos.y > scrRY&&scrPos.y>=-scrMaxH)
	{
		plyPos.y = scrRY;
		scrPos.y -= scrSpeedXY*deltaTime/10;
	}
	if (plyPos.x < scrLX && scrPos.x <= scrMinW)
	{
		plyPos.x = scrLX;
		scrPos.x += scrSpeedLR*deltaTime/10;
	/*	if (bullet != nullptr) {
			bullet->AddScrPos(scrPos.x);
		}*/
	}
	if (plyPos.y < scrLY && scrPos.y <= scrMinH)
	{
		plyPos.y = scrLY;
		scrPos.y -= scrSpeedXY * deltaTime / 10;
	}
}