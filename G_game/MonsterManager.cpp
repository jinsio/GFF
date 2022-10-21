#include "MonsterManager.h"
#include "BaseMonster.h"

MonsterManager* MonsterManager::instance = nullptr;

MonsterManager::MonsterManager()
{
    instance = this;
}

MonsterManager::~MonsterManager()
{
    RemoveAll();
}

void MonsterManager::CreateInstance()
{
    if (!instance)
    {
        instance = new MonsterManager();
    }
}

void MonsterManager::DeleteInstance()
{
    if (instance)
    {
        delete instance;
        instance = nullptr;
    }
}

void MonsterManager::Update(float deltaTime)
{
    for (auto pool : monsterPool)
    {
        pool->Update(deltaTime);
    }
}

void MonsterManager::Draw()
{
    for (auto pool : monsterPool)
    {
        pool->Draw();
    }
}

void MonsterManager::AddMonster(MonsterType type)
{
    BaseMonster* a;
    auto pool = instance->monsterPool;
    switch (type)
    {
    case MonsterManager::MonsterType::slime:
        pool.push_back(a);
        break;
    case MonsterManager::MonsterType::bat:
        pool.push_back(a);
        break;
    case MonsterManager::MonsterType::skeleton:
        pool.push_back(a);
        break;
    case MonsterManager::MonsterType::orc:
        pool.push_back(a);
        break;
    default:
        break;
    }
}

void MonsterManager::RemoveMonster()
{
}

void MonsterManager::RemoveAll()
{
    while (!instance->monsterPool.empty())
    {
        delete instance->monsterPool.back();
        instance->monsterPool.pop_back();
    }
}
