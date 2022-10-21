#pragma once
#include <vector>

class BaseMonster;

class MonsterManager final
{
public:

    enum class MonsterType
    {
        slime = 0,
        bat,
        skeleton,
        orc,
    };

    virtual ~MonsterManager();

    void CreateInstance();
    void DeleteInstance();

    void Update(float deltaTime);
    void Draw();

    void AddMonster(MonsterType type);
    void RemoveMonster();
    void RemoveAll();

private:
    // ƒVƒ“ƒOƒ‹ƒgƒ“
    MonsterManager();

    //! MonsterManager‚ÌŽÀ‘Ì
    static MonsterManager* instance;

    std::vector<BaseMonster*> monsterPool;
};