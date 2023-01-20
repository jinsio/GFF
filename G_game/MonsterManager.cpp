#include "MonsterManager.h"
#include "Monster.h"

/** マネージャの実体へのポインタ定義*/
MonsterManager* MonsterManager::instance = nullptr;

/**
* モンスターマネージャのコンストラクタ（シングルトン）
*/
MonsterManager::MonsterManager()
    : pendingPool()
    , pool()
{
    instance = this;
}

/**
* モンスターマネージャのデストラクタ
*/
MonsterManager::~MonsterManager()
{
    /** 処理なし*/
}

/**
* モンスターマネージャのインスタンス生成
*/
void MonsterManager::CreateInstance()
{
    /** インスタンスがなければ*/
    if (!instance)
    {
        /** 新しく生成する*/
        instance = new MonsterManager();
    }
}

/**
* モンスターマネージャのインスタンス削除
*/
void MonsterManager::DeleteInstance()
{
    /** 全削除*/
    RemoveAll();

    /** インスタンスがあれば*/
    if (instance)
    {
        /** インスタンスを解放する*/
        delete instance;

        /** nullptrを入れておく*/
        instance = nullptr;
    }
}

/**
* モンスターをプールに追加
*/
void MonsterManager::AddMonster(Monster* newObj)
{
    /** 保留プールに一時保存*/
    instance->pendingPool.emplace_back(newObj);
}

/**
* モンスターをプールから削除
*/
void MonsterManager::RemoveMonster(Monster* removeObj)
{
    /** 保留プール内から検索*/
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
* プールの中身全削除
*/
void MonsterManager::RemoveAll()
{
    /** 末尾から保留プールをすべて削除*/
    while (instance->pendingPool.empty())
    {
        delete instance->pendingPool.back();
    }

    /** 末尾からプールをすべて削除*/
    while (instance->pool.empty())
    {
        delete instance->pool.back();
        instance->pool.pop_back();
    }
}

void MonsterManager::Update(float deltaTime)
{
    /** すべてのモンスターの更新*/
    for (int i = 0; i < instance->pool.size(); ++i)
    {
        instance->pool[i]->Update(deltaTime);
    }

    /** 保留しているモンスターをアクティブリストに追加*/
    for (auto pending : instance->pendingPool)
    {
        instance->pool.emplace_back(pending);
    }

    instance->pendingPool.clear();

    /** 死んでいるモンスターをdeadPoolへ一時保管*/
    vector<Monster*> deadPool;

    auto pool = instance->pool;

    /** 死んでいるモンスターを検索してdeadPoolへ移動*/
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
* プール内の全モンスターの描画
*/
void MonsterManager::Draw()
{
    for (auto pool : instance->pool)
    {
        //pool->Draw();
    }
}
