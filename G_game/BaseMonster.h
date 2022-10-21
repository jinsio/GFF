#pragma once
#include "monsterInfo.h"

class BaseMonster
{
public:
    BaseMonster();
    virtual ~BaseMonster();

    virtual void Update(float deltaTime) = 0;
    virtual void Draw();

protected:

    //! 位置
    vec2 pos = { 0 };

    //! 大きさ
    vec2 scale = { 0 };

    //! 大きさ（半分）
    vec2 halfScale = { 0 };

    //! 速度
    float speed;

    //! 表示用
    int displayImage;

    //! 移動アニメーション画像
    int moveAnim[moveAnimNum] = { -1 };

    //! 攻撃アニメーション画像
    int attackAnim[attackAnimNum] = { -1 };

    //! 被弾アニメーション画像
    int damageAnim[damageAnimNum] = { -1 };

    //! 体力
    int hp;

    //! 生きているかどうか
    bool isAlive;

    //! 味方かどうか
    bool isAlly;

    //! 右向きかどうか
    bool isDirRight;

    //! tmp
    int i;
};
