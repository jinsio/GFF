#pragma once
#include <vector>

using namespace std;

class Monster;

class MonsterManager final
{
public:
    /** インスタンスの生成*/
    static void CreateInstance();

    /** インスタンスの削除*/
    static void DeleteInstance();

    /** モンスターをプールに追加*/
    static void AddMonster(Monster* newObj);

    /** モンスターをプールから削除*/
    static void RemoveMonster(Monster* removeObj);

    /** プールの中身全削除*/
    static void RemoveAll();

    /** 更新*/
    static void Update(float deltaTime);

    /** 描画*/
    static void Draw();

private:
    /** コンストラクタ（シングルトン）*/
    MonsterManager();

    /** デストラクタ*/
    ~MonsterManager();

    /** マネージャの実体*/
    static MonsterManager* instance;

    /** 保留プール*/
    vector<Monster*> pendingPool;

    /** プール*/
    vector<Monster*> pool;
};