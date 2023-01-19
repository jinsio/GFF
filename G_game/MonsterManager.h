#pragma once
#include <vector>

using namespace std;

class Monster;

class MonsterManager final
{
public:
    /** �C���X�^���X�̐���*/
    static void CreateInstance();

    /** �C���X�^���X�̍폜*/
    static void DeleteInstance();

    /** �����X�^�[���v�[���ɒǉ�*/
    static void AddMonster(Monster* newObj);

    /** �����X�^�[���v�[������폜*/
    static void RemoveMonster(Monster* removeObj);

    /** �v�[���̒��g�S�폜*/
    static void RemoveAll();

    /** �X�V*/
    static void Update(float deltaTime);

    /** �`��*/
    static void Draw();

private:
    /** �R���X�g���N�^�i�V���O���g���j*/
    MonsterManager();

    /** �f�X�g���N�^*/
    ~MonsterManager();

    /** �}�l�[�W���̎���*/
    static MonsterManager* instance;

    /** �ۗ��v�[��*/
    vector<Monster*> pendingPool;

    /** �v�[��*/
    vector<Monster*> pool;
};