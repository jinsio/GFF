#include "GameObjectManager.h"
#include "GameObject.h"


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
void GameObjectManager::Entry(GameObject* newObj)
{
	// �y���f�B���O�I�u�W�F�N�g�Ɉꎞ�ۑ�
	mpInstance->mPendingObjects.push_back(newObj);
}

//------------------------------------------------------------------------------
// @brief GameObject ���}�l�[�W������폜
// @param[in] releaseObj �폜�������I�u�W�F�N�g�̃|�C���^
// @detail �폜�������I�u�W�F�N�g�̃|�C���^���}�l�[�W�����Ō������폜����
//------------------------------------------------------------------------------
void GameObjectManager::Release(GameObject* releaseObj)
{
	// �y���f�B���O�I�u�W�F�N�g�����猟��
	auto iter = std::find(mpInstance->mPendingObjects.begin(), mpInstance->mPendingObjects.end(), releaseObj);
	if (iter != mpInstance->mPendingObjects.end())
	{
		// �������I�u�W�F�N�g���Ō���Ɉړ����ăf�[�^������
		std::iter_swap(iter, mpInstance->mPendingObjects.end() - 1);
		mpInstance->mPendingObjects.pop_back();

		return;
	}

	// ����I�u�W�F�N�g�̃^�O��ނ𓾂�
	GameObjectTag tag = releaseObj->GetTag();

	// �A�N�e�B�u�I�u�W�F�N�g������폜Object������
	iter = std::find(mpInstance->mObjects[tag].begin(), mpInstance->mObjects[tag].end(), releaseObj);
	if (iter != mpInstance->mObjects[tag].end())
	{
		// �������I�u�W�F�N�g�𖖔��Ɉړ����A�폜
		std::iter_swap(iter, mpInstance->mObjects[tag].end() - 1);
		delete mpInstance->mObjects[tag].back();
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

	// ���ׂẴA�N�e�B�u�I�u�W�F�N�g���폜
	for (auto& tag : ObjectTagAll)
	{
		// ��������폜
		while (!mpInstance->mObjects[tag].empty())
		{
			delete mpInstance->mObjects[tag].back();
			mpInstance->mObjects[tag].pop_back();
		}
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
	for (auto& tag : ObjectTagAll)
	{
		// �Y���^�O�ɂ��邷�ׂẴI�u�W�F�N�g���X�V
		for (int i = 0; i < mpInstance->mObjects[tag].size(); ++i)
		{
			mpInstance->mObjects[tag][i]->Update(deltaTime);
		}
	}

	// �y���f�B���O���̃I�u�W�F�N�g���A�N�e�B�u���X�g�ɒǉ�
	for (auto pending : mpInstance->mPendingObjects)
	{
		GameObjectTag tag = pending->GetTag();
		mpInstance->mObjects[tag].emplace_back(pending);
	}
	mpInstance->mPendingObjects.clear();

	// ����ł���Object��deadObject�ֈꎞ�ۊǂ������ƁA
	 // vector����r��
	std::vector<GameObject*> deadObjects;
	for (auto& tag : ObjectTagAll)
	{
		// deadObject�ֈړ�
		for (auto obj : mpInstance->mObjects[tag])
		{
			if (!obj->GetAlive())
			{
				deadObjects.emplace_back(obj);
			}
		}
		// mObjects[tag]���玀��ł���I�u�W�F�N�g�̂�vector���珜�O�̂ݍs��
		// �܂�GameObject��delete�͍s��Ȃ�
		// vector����remove_if�̎g�����ɂ��Ă͉��LURL�Q�l
		// https://programming-place.net/ppp/contents/cpp2/main/remove_element.html#remove_if
		mpInstance->mObjects[tag].erase(std::remove_if(std::begin(mpInstance->mObjects[tag]), std::end(mpInstance->mObjects[tag]), [](GameObject* g) { return !g->GetAlive(); }), std::cend(mpInstance->mObjects[tag]));
	}

	// ����ł���GameObject��������delete
	while (!deadObjects.empty())
	{
		delete deadObjects.back();
		deadObjects.pop_back();
	}
}


//-------------------------------------------------------------------------------
// @brief �S�I�u�W�F�N�g�̕`�揈��.
//-------------------------------------------------------------------------------
void GameObjectManager::Draw(int offSetX, int offSetY)
{
	for (auto& tag : ObjectTagAll)
	{
		for (int i = 0; i < mpInstance->mObjects[tag].size(); ++i)
		{
			// �`��\�ȃI�u�W�F�N�g�̂ݕ`��
			if (mpInstance->mObjects[tag][i]->GetVisible())
			{
				mpInstance->mObjects[tag][i]->Draw(offSetX, offSetY);
			}
		}
	}
}

////-------------------------------------------------------------------------------
//// @brief �S�I�u�W�F�N�g�̓����蔻��.
////-------------------------------------------------------------------------------
//void PlayerObjectManager::Collision()
//{
//	//////////////////////////////////////
//	// �����蔻��g�ݍ��킹�������ɏ���
//	//////////////////////////////////////
//	// player vs BackGround ���ׂĂ̑g�ݍ��킹�`�F�b�N
//	for (int playernum = 0; playernum < mpInstance->mObjects[ObjectTag::Player].size(); ++playernum)
//	{
//		for (int bgnum = 0; bgnum < mpInstance->mObjects[ObjectTag::BackGround].size(); ++bgnum)
//		{
//			mpInstance->mObjects[ObjectTag::Player][playernum]->
//				OnCollisonEnter(mpInstance->mObjects[ObjectTag::BackGround][bgnum]);
//		}
//	}
//}
//-------------------------------------------------------------------------------
// @brief �^�O��ނ̏��߂̃I�u�W�F�N�g��Ԃ�.
// @param[in] tag ObjectTag���
//-------------------------------------------------------------------------------
GameObject* GameObjectManager::GetFirstGameObject(GameObjectTag tag)
{
	if (mpInstance->mObjects[tag].size() == 0)
	{
		return nullptr;
	}
	return mpInstance->mObjects[tag][0];
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