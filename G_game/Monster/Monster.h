#pragma once
#include "monsterInfo.h"

class Monster
{
public:
    /** コンストラクタ*/
    Monster();

    /** 仮想デストラクタ*/
    virtual ~Monster();

    /** 更新（純粋仮想関数）*/
    virtual void Update(float deltaTime) = 0;

    /** 描画（仮想関数）*/
    void Draw();

    /** 生きているかどうかの取得*/
    bool GetAlive() { return isAlive; }

protected:
    /** 座標*/
    VECTOR pos = { 0 };

    /** 大きさ*/
    VECTOR scale = { 0 };

    /** 大きさ（半分）*/
    VECTOR halfScale = { 0 };

    /** 速度*/
    float speed;
    
    /** 重力*/
    float gravity;

    /** 描画用*/
    int handle;

    /** 移動アニメーション*/
    int moveAnim[moveAnimNum] = { -1 };

    /** 攻撃アニメーション*/
    int attackAnim[attackAnimNum] = { -1 };

    /** 被弾アニメーション*/
    int damageAnim[damageAnimNum] = { -1 };

    /** 体力*/
    int hp;

    /** 生きているかどうか*/
    bool isAlive;

    /** 味方かどうか*/
    bool isAlly;

    /** 右向きかどうか*/
    bool isDirRight;

    //! tmp
    int i;
};