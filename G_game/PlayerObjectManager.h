//------------------------------------------------------------------------------
// @brief �Q�[���I�u�W�F�N�g�}�l�[�W��
//------------------------------------------------------------------------------
#pragma once

#include <vector>
#include <unordered_map>
#include <DxLib.h>

#include "PlayerObject.h"
#include <math.h>

namespace My3dApp
{
	class GameObjectManager final
	{
	public:
		static void Initialize();                              // �Q�[���I�u�W�F�N�g�}�l�[�W���̏���������
		static void Entry(PlayerObject* newObj);                 // �Q�[���I�u�W�F�N�g�o�^
		static void Release(PlayerObject* releaseObj);           // �Q�[���I�u�W�F�N�g�폜
		static void ReleaseAllObj();                           // �S�I�u�W�F�N�g�폜

		static void Update(float deltaTime);                   // �S�I�u�W�F�N�g�̍X�V����
		static void Draw();                                    // �`�� 

		static void Finalize();

	private:
		GameObjectManager();                                   // �V���O���g��
		~GameObjectManager();                                  // �Q�[���I�u�W�F�N�g�}�l�[�W���f�X�g���N�^
		static GameObjectManager* mpInstance;                  // �}�l�[�W���̎��́i�A�v�����ɗB�ꑶ��)
		std::vector<PlayerObject*>  mPendingObjects;             // �ꎞ�ҋ@�I�u�W�F�N�g
		std::vector<PlayerObject*>  mObjects;                    // mObjects[�^�O���][�I�u�W�F�N�g��]; 
	};

}// namespace My3dApp
