#include "MonsterManager.h"
#include "Monster.h"
#include "Slime.h"
#include "Bat.h"
#include "Skeleton.h"
#include "Orc.h"

MonsterManager* MonsterManager::instance = nullptr;

//------------------------------------------------------------------------------------------------//
// @brief MonsterManager�̃R���X�g���N�^
//------------------------------------------------------------------------------------------------//
MonsterManager::MonsterManager()
{
    instance = this;
}

//------------------------------------------------------------------------------------------------//
// @brief MonsterManager�̃f�X�g���N�^
//------------------------------------------------------------------------------------------------//
MonsterManager::~MonsterManager()
{
    RemoveAll();
}

//------------------------------------------------------------------------------------------------//
// @brief MonsterManager�̃C���X�^���X�̐���
//------------------------------------------------------------------------------------------------//
void MonsterManager::CreateInstance()
{
    if (!instance)
    {
        instance = new MonsterManager();
    }
}

//------------------------------------------------------------------------------------------------//
// @brief MonsterManager�̃C���X�^���X�̍폜
//------------------------------------------------------------------------------------------------//
void MonsterManager::DeleteInstance()
{
    if (instance)
    {
        delete instance;
        instance = nullptr;
    }
}

//------------------------------------------------------------------------------------------------//
// @brief MonsterManager�̍X�V����
//------------------------------------------------------------------------------------------------//
void MonsterManager::Update(float deltaTime)
{
    for (auto pool : monsterPool)
    {
        pool->Update(deltaTime);
    }
}

//------------------------------------------------------------------------------------------------//
// @brief MonsterManager�̕`�揈��
//------------------------------------------------------------------------------------------------//
void MonsterManager::Draw()
{
    for (auto pool : monsterPool)
    {
        pool->Draw();
    }
}

//------------------------------------------------------------------------------------------------//
// @brief Monster�̒ǉ�
//------------------------------------------------------------------------------------------------//
void MonsterManager::AddMonster(MonsterType type)
{
    auto pool = instance->monsterPool;
    switch (type)
    {
    case MonsterManager::MonsterType::slime:
        pool.push_back(new Slime());
        break;
    case MonsterManager::MonsterType::bat:
        pool.push_back(new Bat());
        break;
    case MonsterManager::MonsterType::skeleton:
        pool.push_back(new Skeleton());
        break;
    case MonsterManager::MonsterType::golem:
        pool.push_back(new Orc());
        break;
    default:
        break;
    }
}

//------------------------------------------------------------------------------------------------//
// @brief �����Monster�̍폜
//------------------------------------------------------------------------------------------------//
void MonsterManager::RemoveMonster()
{
}


//------------------------------------------------------------------------------------------------//
// @brief �S�Ă�Monster�̍폜
//------------------------------------------------------------------------------------------------//
void MonsterManager::RemoveAll()
{
    while (!instance->monsterPool.empty())
    {
        delete instance->monsterPool.back();
        instance->monsterPool.pop_back();
    }
}
