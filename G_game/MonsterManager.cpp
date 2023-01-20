#include "MonsterManager.h"
#include "Monster.h"

/** �}�l�[�W���̎��̂ւ̃|�C���^��`*/
MonsterManager* MonsterManager::instance = nullptr;

/**
* �����X�^�[�}�l�[�W���̃R���X�g���N�^�i�V���O���g���j
*/
MonsterManager::MonsterManager()
    : pendingPool()
    , pool()
{
    instance = this;
}

/**
* �����X�^�[�}�l�[�W���̃f�X�g���N�^
*/
MonsterManager::~MonsterManager()
{
    /** �����Ȃ�*/
}

/**
* �����X�^�[�}�l�[�W���̃C���X�^���X����
*/
void MonsterManager::CreateInstance()
{
    /** �C���X�^���X���Ȃ����*/
    if (!instance)
    {
        /** �V������������*/
        instance = new MonsterManager();
    }
}

/**
* �����X�^�[�}�l�[�W���̃C���X�^���X�폜
*/
void MonsterManager::DeleteInstance()
{
    /** �S�폜*/
    RemoveAll();

    /** �C���X�^���X�������*/
    if (instance)
    {
        /** �C���X�^���X���������*/
        delete instance;

        /** nullptr�����Ă���*/
        instance = nullptr;
    }
}

/**
* �����X�^�[���v�[���ɒǉ�
*/
void MonsterManager::AddMonster(Monster* newObj)
{
    /** �ۗ��v�[���Ɉꎞ�ۑ�*/
    instance->pendingPool.emplace_back(newObj);
}

/**
* �����X�^�[���v�[������폜
*/
void MonsterManager::RemoveMonster(Monster* removeObj)
{
    /** �ۗ��v�[�������猟��*/
    auto pendingPool = instance->pendingPool;
    auto itr = find(pendingPool.begin(), pendingPool.end(), removeObj);
    if (itr != pendingPool.end())
    {
        iter_swap(itr, pendingPool.end() - 1);
        pendingPool.pop_back();

        return;
    }

    auto pool = instance->pool;
    itr = find(pool.begin(), pool.end(), removeObj);
    if (itr != pool.end())
    {
        iter_swap(itr, pool.end() - 1);
        delete pool.back();
    }
}

/**
* �v�[���̒��g�S�폜
*/
void MonsterManager::RemoveAll()
{
    /** ��������ۗ��v�[�������ׂč폜*/
    while (instance->pendingPool.empty())
    {
        delete instance->pendingPool.back();
    }

    /** ��������v�[�������ׂč폜*/
    while (instance->pool.empty())
    {
        delete instance->pool.back();
        instance->pool.pop_back();
    }
}

void MonsterManager::Update(float deltaTime)
{
    /** ���ׂẴ����X�^�[�̍X�V*/
    for (int i = 0; i < instance->pool.size(); ++i)
    {
        instance->pool[i]->Update(deltaTime);
    }

    /** �ۗ����Ă��郂���X�^�[���A�N�e�B�u���X�g�ɒǉ�*/
    for (auto pending : instance->pendingPool)
    {
        instance->pool.emplace_back(pending);
    }

    instance->pendingPool.clear();

    /** ����ł��郂���X�^�[��deadPool�ֈꎞ�ۊ�*/
    vector<Monster*> deadPool;

    auto pool = instance->pool;

    /** ����ł��郂���X�^�[����������deadPool�ֈړ�*/
    for (int i = 0; i < pool.size(); ++i)
    {
        if (!pool[i]->GetAlive())
        {
            deadPool.emplace_back(pool[i]);
            pool.erase(remove_if(begin(pool), end(pool), [](Monster* p) {return !p->GetAlive(); }), cend(pool));
        }
    }

    while (!deadPool.empty())
    {
        delete deadPool.back();
        deadPool.pop_back();
    }
}

/**
* �v�[�����̑S�����X�^�[�̕`��
*/
void MonsterManager::Draw()
{
    for (auto pool : instance->pool)
    {
        //pool->Draw();
    }
}
