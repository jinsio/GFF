#pragma once

#include "monsterInfo.h"

/// <summary>
/// モンスタークラス
/// </summary>
class Monster
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

    /// <summary>
    /// モンスターの更新（純粋仮想関数）
    /// </summary>
    /// <param name="deltaTime">1フレームの経過時間</param>
    virtual void Update(float deltaTime) = 0;

    /// <summary>
    /// モンスターの描画
    /// </summary>
    void Draw();

    /// <summary>
    /// 生死状態の取得
    /// </summary>
    /// <returns>生きていればtrue 死んでいたらfalse</returns>
    bool GetAlive() { return alive; }

protected:
    // 座標
    VECTOR pos = { 0 };

    // 大きさ
    VECTOR scale = { 0 };

    // 大きさ（半分）
    VECTOR halfScale = { 0 };

    // 速度
    float speed;
    
    // 重力
    float gravity;

    // 描画ハンドル
    int handle;

    // 移動アニメーション
    int moveAnim[moveAnimNum] = { -1 };

    // 攻撃アニメーション
    int attackAnim[attackAnimNum] = { -1 };

    // 被弾アニメーション
    int damageAnim[damageAnimNum] = { -1 };

    // 体力
    int hp;

    // 生死状態
    bool alive;

    // 右を向いているか
    bool dirRight;

    /// <summary>
    /// 生死状態の確認
    /// </summary>
    void CheckAlive();

};