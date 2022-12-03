#pragma once

// �C���N���[�h
#include "SceneBase.h"
#include "PlayerObjectManager.h"
class Map;
class Collision;
class Scroll;
class Player;
class Bullet;
class Button;
class ShotDummy;
/* �v���C�V�[�� */
class PlayScene :public SceneBase
{
private:
	
	Map* map;
	Collision* collision;
	Scroll* scroll;
	Player* player;
	Button* button;
	ShotDummy* dummy;

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
	/// �L�������o���b�g�𓊂���܂ł̗���
	/// </summary>
	void ShotFlow(float _deltaTime);
	/// <summary>
	/// �V�[���ƃL�����̕`��
	/// </summary>
	void Draw()override;
};

