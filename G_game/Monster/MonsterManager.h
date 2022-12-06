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
    /** �R���X�g���N�^�i�V���O���g���j*/
    MonsterManager();

    /** �f�X�g���N�^*/
    ~MonsterManager();

    /** �}�l�[�W���̃C���X�^���X*/
    static MonsterManager* instance;

    /** Monster�̃I�u�W�F�N�g�v�[��*/
    std::vector<Monster*> monsterPool;
};