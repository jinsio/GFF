#include "PlayerObjectManager.h"
#include "PlayerObject.h"

namespace My3dApp
{
	// GameObjectManager���̂ւ̃|�C���^��`
	GameObjectManager* GameObjectManager::mpInstance = nullptr;

	//------------------------------------------------------------------------------
	// @brief �Q�[���I�u�W�F�N�g�}�l�[�W���@�R���X�g���N�^
	//------------------------------------------------------------------------------
	GameObjectManager::GameObjectManager()
		: mObjects()
	{
		mpInstance = nullptr;
	}
	//------------------------------------------------------------------------------
	// @brief �Q�[���I�u�W�F�N�g�}�l�[�W���@�f�X�g���N�^
	//------------------------------------------------------------------------------
	GameObjectManager::~GameObjectManager()
	{
		ReleaseAllObj();
	}

	//------------------------------------------------------------------------------
	// @brief �Q�[���I�u�W�F�N�g�}�l�[�W���̏������֐�
	// �Q�[���I�u�W�F�N�g�}�l�[�W��������������B���̊֐��ȍ~�A�ق��̊֐���
	// �g�p�ł���悤�ɂȂ�B���̂��ߑ��̊֐��g�p�O��Create���Ăяo���K�v������B
	//------------------------------------------------------------------------------
	void GameObjectManager::Initialize()
	{
		if (!mpInstance)
		{
			mpInstance = new GameObjectManager;
		}
	}

	//------------------------------------------------------------------------------
	// @brief GameObject ��GameObject�}�l�[�W���ɒǉ�
	// @param[in] newObj �V�K�쐬�Q�[���I�u�W�F�N�g
	// @detail �V�K�Q�[���I�u�W�F�N�g���}�l�[�W���[�ɒǉ�����B�����ňꎞ�ۊǂ��ꂽ��A
	// Update()���Ń^�O��ޖ��ɕ��ނ���Ǘ������B
	//------------------------------------------------------------------------------
	void GameObjectManager::Entry(PlayerObject* newObj)
	{
		// �y���f�B���O�I�u�W�F�N�g�Ɉꎞ�ۑ�
		mpInstance->mPendingObjects.emplace_back(newObj);
	}

	//------------------------------------------------------------------------------
	// @brief GameObject ���}�l�[�W������폜
	// @param[in] releaseObj �폜�������I�u�W�F�N�g�̃|�C���^
	// @detail �폜�������I�u�W�F�N�g�̃|�C���^���}�l�[�W�����Ō������폜����
	//------------------------------------------------------------------------------
	void GameObjectManager::Release(PlayerObject* releaseObj)
	{
		// �y���f�B���O�I�u�W�F�N�g�����猟��
		auto iter = std::find(mpInstance->mPendingObjects.begin(),
			mpInstance->mPendingObjects.end(), releaseObj);
		if (iter != mpInstance->mPendingObjects.end())
		{
			// �������I�u�W�F�N�g���Ō���Ɉړ����ăf�[�^������
			std::iter_swap(iter, mpInstance->mPendingObjects.end() - 1);
			mpInstance->mPendingObjects.pop_back();

			return;
		}

		// �A�N�e�B�u�I�u�W�F�N�g������폜Object������
		iter = std::find(mpInstance->mObjects.begin(),
			mpInstance->mObjects.end(), releaseObj);
		if (iter != mpInstance->mObjects.end())
		{
			// �������I�u�W�F�N�g�𖖔��Ɉړ����A�폜
			std::iter_swap(iter, mpInstance->mObjects.end() - 1);
			delete mpInstance->mObjects.back();
		}
	}

	//-------------------------------------------------------------------------------
	// @brief �S�I�u�W�F�N�g�폜.
	//-------------------------------------------------------------------------------
	void GameObjectManager::ReleaseAllObj()
	{
		// ��������y���f�B���O�I�u�W�F�N�g�����ׂĂ��폜
		while (!mpInstance->mPendingObjects.empty())
		{
			delete mpInstance->mPendingObjects.back();
		}

		// ��������폜
		while (!mpInstance->mObjects.empty())
		{
			delete mpInstance->mObjects.back();
			mpInstance->mObjects.pop_back();
		}
	}

	//-------------------------------------------------------------------------------
	// @brief �S�I�u�W�F�N�g�̍X�V����.
	// @param[in] 1�t���[���̍X�V����.
	// 
	// @detail �S�I�u�W�F�N�g��Update���\�b�h���Ă񂾂��ƁA
	// �V�KObject���A�N�e�B�u���X�g�ɒǉ�
	// ���SObject���A�N�e�B�u���X�g����폜
	//-------------------------------------------------------------------------------
	void GameObjectManager::Update(float deltaTime)
	{
		// ���ׂẴA�N�^�[�̍X�V
		// �Y���^�O�ɂ��邷�ׂẴI�u�W�F�N�g���X�V
		for (int i = 0; i < mpInstance->mObjects.size(); ++i)
		{
			mpInstance->mObjects[i]->Update(deltaTime);
		}

		// �y���f�B���O���̃I�u�W�F�N�g���A�N�e�B�u���X�g�ɒǉ�
		for (auto pending : mpInstance->mPendingObjects)
		{
			mpInstance->mObjects.emplace_back(pending);
		}

		mpInstance->mPendingObjects.clear();

		// ���ׂẴA�N�^�[���Ŏ���ł���A�N�^�[��deadObject�ֈꎞ�ۊ�
		std::vector<PlayerObject*> deadObjects;
		// ���SObject���������AdeadObjects��
		for (int i = 0; i < mpInstance->mObjects.size(); ++i)
		{
			// �����Ă��Ȃ�������deadObject�ֈړ�
			if (!mpInstance->mObjects[i]->GetAlive())
			{
				deadObjects.emplace_back(mpInstance->mObjects[i]);
			}
		}

		// ����ł���I�u�W�F�N�g��delete
		for (auto deadObj : deadObjects)
		{
			delete deadObj;
		}
		deadObjects.clear();
	}

	//-------------------------------------------------------------------------------
	// @brief �S�I�u�W�F�N�g�̕`�揈��.
	//-------------------------------------------------------------------------------
	void GameObjectManager::Draw()
	{
		for (int i = 0; i < mpInstance->mObjects.size(); ++i)
		{
			mpInstance->mObjects[i]->Draw();
		}
	}

	//-------------------------------------------------------------------------------
	// @brief  GameObjectManager�̌�n������.
	// @detail �A�v���P�[�V�����I���O�ɌĂяo���K�v������B�}�l�[�W�����m�ۂ����̈��
	// �}�l�[�W�����g�̉���������s���BEnd���s�킸�ɏI�������ꍇ�̓��������[�N���N�����B
	// �܂��A���̊֐��ȍ~�͂��ׂĂ�GameObjectManager�̊֐��͎g�p���邱�Ƃ͂ł��Ȃ��B
	//-------------------------------------------------------------------------------
	void GameObjectManager::Finalize()
	{
		ReleaseAllObj();
		if (mpInstance)
		{
			delete mpInstance;
			mpInstance = nullptr;
		}
	}

}// namespace My3dApp
