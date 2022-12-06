#include "MonsterManager.h"
#include "Monster.h"
#include "Slime.h"
#include "Bat.h"
#include "Skeleton.h"
#include "Orc.h"

MonsterManager* MonsterManager::instance = nullptr;

//------------------------------------------------------------------------------------------------//
// @brief MonsterManagerのコンストラクタ
//------------------------------------------------------------------------------------------------//
MonsterManager::MonsterManager()
{
    instance = this;
}

//------------------------------------------------------------------------------------------------//
// @brief MonsterManagerのデストラクタ
//------------------------------------------------------------------------------------------------//
MonsterManager::~MonsterManager()
{
    RemoveAll();
}

//------------------------------------------------------------------------------------------------//
// @brief MonsterManagerのインスタンスの生成
//------------------------------------------------------------------------------------------------//
void MonsterManager::CreateInstance()
{
    if (!instance)
    {
        instance = new MonsterManager();
    }
}

//------------------------------------------------------------------------------------------------//
// @brief MonsterManagerのインスタンスの削除
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
// @brief MonsterManagerの更新処理
//------------------------------------------------------------------------------------------------//
void MonsterManager::Update(float deltaTime)
{
    for (auto pool : monsterPool)
    {
        pool->Update(deltaTime);
    }
}

//------------------------------------------------------------------------------------------------//
// @brief MonsterManagerの描画処理
//------------------------------------------------------------------------------------------------//
void MonsterManager::Draw()
{
    for (auto pool : monsterPool)
    {
        pool->Draw();
    }
}

//------------------------------------------------------------------------------------------------//
// @brief Monsterの追加
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
// @brief 特定のMonsterの削除
//------------------------------------------------------------------------------------------------//
void MonsterManager::RemoveMonster()
{
}


//------------------------------------------------------------------------------------------------//
// @brief 全てのMonsterの削除
//------------------------------------------------------------------------------------------------//
void MonsterManager::RemoveAll()
{
    while (!instance->monsterPool.empty())
    {
        delete instance->monsterPool.back();
        instance->monsterPool.pop_back();
    }
}
