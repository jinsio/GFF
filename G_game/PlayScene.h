#pragma once

// �C���N���[�h
#include "SceneBase.h"

class Map;
class Collision;
class Player;


/* �v���C�V�[�� */
class PlayScene :public SceneBase
{
private:
	Map* map;
	Collision* collision;
	Player* player;

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
	/// �V�[���ƃL�����̕`��
	/// </summary>
	void Draw()override;
};

