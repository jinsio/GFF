#include "Scroll.h"
#include "Bullet.h"
// @brief Scroll�R���X�g���N�^�\ //

Bullet* bullet;

Scroll::Scroll()
	:scrollX(0)
	,scrollY(0)
	,dx(0)
	,dy(0)
{
	sclMaxX = 40 * 162 - 1920;
	sclMaxY = 40 * 58 - 1080;
	sclMinX = 0;
	sclMinY = 0;
}

// @brief Scroll�f�X�g���N�^�[ //

Scroll::~Scroll()
{
}

// @brief Scroll�ړ����� //

void Scroll::Update(float deltaTime,VECTOR& plyPos)
{
	dx = dy = 0;

	//---�v���C���[�����߂�����---//
	if (plyPos.x +64  > scrollX + scrMaxW)				//�E�ɃX�N���[��������W�𒴂�����
	{
		dx = plyPos.x+64 - (scrollX + scrMaxW);			//���ɉ����߂�
	}
	if (plyPos.y + 64 > scrollY + scrMaxH)				//���X�N���[��
	{
		dy = plyPos.y+64 - (scrollY + scrMaxH);
	}
	if (plyPos.x-64 < scrollX + scrMinW)					//���X�N���[��
	{
		dx = plyPos.x-64 - (scrollX + scrMinW);
	}
	if (plyPos.y-64 < scrollY + scrMinH)					//��X�N���[��
	{
		dy = plyPos.y-64 - (scrollY + scrMinH);
	}

	scrollX += dx;										//�����߂�X
	scrollY += dy;										//�����߂�Y

	//---�X�N���[�����W�ő�l����---//
	if (scrollX > sclMaxX)								//�E�X�N���[�����W�ő�l�܂ł�����
	{
		scrollX = sclMaxX;								//�X�N���[����~
	}
	else if (scrollX < sclMinX)							//���X�N���[��
	{
		scrollX = sclMinX;
	}
	if (scrollY > sclMaxY)								//���X�N���[��
	{
		scrollY = sclMaxY;
	}
	else if (scrollY < sclMinY)							//��X�N���[��
	{
		scrollY = sclMinY;
	}
}

// @brief �X�N���[���̕`��I�t�Z�b�gX���擾 //

int Scroll::GetDrawOffSetX()
{
	return static_cast<int>(scrollX);
}

// @brief �X�N���[���̕`��I�t�Z�b�gY���擾 //

int Scroll::GetDrawOffSetY()
{
	return static_cast<int>(scrollY);
}