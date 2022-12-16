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
	sclMaxY = 40 * 54 - 1080;
	sclMinX = -40;
	sclMinY = -40;
}

// @brief Scroll�f�X�g���N�^�[ //

Scroll::~Scroll()
{
}

// @brief Scroll�ړ����� //

void Scroll::Update(float deltaTime,VECTOR& plyPos)
{
	//---�v���C���[�����߂�����---//
	if (plyPos.x + 64 > scrollX + scrMaxW)				//�E�X�N���[��
	{
		dx = plyPos.x - (scrollX + scrMaxW);
	}
	if (plyPos.y + 64 > scrollY + scrMaxH)				//���X�N���[��
	{
		dy = plyPos.y - (scrollY + scrMaxH);
	}
	if (plyPos.x < scrollX + scrMinW)					//���X�N���[��
	{
		dx = plyPos.x - (scrollY + scrMinW);
	}
	if (plyPos.y < scrollY + scrMinH)					//��X�N���[��
	{
		dy = plyPos.y - (scrollY + scrMinH);
	}

	scrollX += dx;
	scrollY += dy;

	if (scrollX > sclMaxX)
	{
		scrollX = sclMaxX;
	}
	else if (scrollX < sclMinX)
	{
		scrollX = sclMinX;
	}
	if (scrollY > sclMaxY)
	{
		scrollY = sclMaxY;
	}
	else if (scrollY < sclMinY)
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