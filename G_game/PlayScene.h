#pragma once

// �C���N���[�h
#include "SceneBase.h"

class Map;
class Collision;
class Player;
class Bullet;

/* �v���C�V�[�� */
class PlayScene :public SceneBase
{
private:
	Map* map;
	Collision* collision;
	Player* player;
	Bullet* bullet;
public:
	// �R���X�g���N�^
	PlayScene();
	// �f�X�g���N�^
	~PlayScene();

	/// <summary>
	/// �V�[���̍X�V����
	/// </summary>
	/// <returns>���݂̃V�[���̃|�C���^</returns>
	SceneBase* Update(float _deltaTime)override;

	/// <summary>
	/// �L�������n�ʂɗ����Ă��邩�ǂ������ׂ�
	/// </summary>
	void isStand();
	/// <summary>
	/// �v���C���[�e���ˏ���
	/// </summary>
	void SetBullet();
	/// <summary>
	/// �V�[���ƃL�����̕`��
	/// </summary>
	void Draw()override;
};

