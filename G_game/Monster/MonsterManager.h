#pragma once
#include <vector>

class Monster;

class MonsterManager final
{
public:

    enum class MonsterType
    {
        slime = 0,
        bat,
        skeleton,
        golem,
    };


    void CreateInstance();
    void DeleteInstance();

    void Update(float deltaTime);
    void Draw();

    void AddMonster(MonsterType type);
    void RemoveMonster();
    void RemoveAll();

private:
    /** コンストラクタ（シングルトン）*/
    MonsterManager();

    /** デストラクタ*/
    ~MonsterManager();

    /** マネージャのインスタンス*/
    static MonsterManager* instance;

    /** Monsterのオブジェクトプール*/
    std::vector<Monster*> monsterPool;
};