#pragma once

#include "DxLib.h"
#include "monsterInfo.h"
#include "GameObject.h"

/// <summary>
/// モンスタークラス
/// </summary>
class Monster : public GameObject
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Monster();

    /// <summary>
    /// 仮想デストラクタ
    /// </summary>
    virtual ~Monster();

protected:
    // 大きさ
    VECTOR scale = { 0 };

    // 大きさ（半分）
    VECTOR halfScale = { 0 };

    // 速度
    float speed;

    // 移動アニメーション
    int moveAnim[4] = { -1 };

    // 攻撃アニメーション
    int attackAnim[4] = { -1 };

    // 被弾アニメーション
    int damageAnim[2] = { -1 };

    // 自身の状態
    int state;

    // 状態の列挙
    enum State
    {
        IDLE = 0,  // 待機
        TRACK,     // 追跡
        ATTACK,    // 攻撃
        DEAD,      // 死亡
    };

    enum AtkState
    {
        START = 0,  // 攻撃開始
        NOW,        // 最中
        FINISH,     // 攻撃終了
    };

    // 攻撃の状態
    int atkState;

    // 体力
    int hp;

    /// <summary>
    /// 生死状態の確認
    /// </summary>
    void CheckAlive();

    /// <summary>
    /// 追跡処理
    /// </summary>
    virtual void Track(float deltaTime) {};

    /// <summary>
    /// 攻撃処理
    /// </summary>
    virtual void  Attack(float deltaTime) {};

};