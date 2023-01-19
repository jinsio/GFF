#pragma once

#include "Monster.h"

/// <summary>
/// ゴーレムクラス
/// </summary>
class Golem : public Monster
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Golem();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Golem();

    /// <summary>
    /// ゴーレムの更新処理
    /// </summary>
    /// <param name="deltaTime">1フレームの経過時間</param>
    void Update(float deltaTime) override;

private:
    /// <summary>
    /// ゴーレムの追跡処理
    /// </summary>
    /// <param name="deltaTime">1フレームの経過時間</param>
    void Track(float deltaTime) override;

    /// <summary>
    /// ゴーレムの攻撃処理
    /// </summary>
    /// <param name="deltaTime">1フレームの経過時間</param>
    void Attack(float deltaTime) override;

    /// <summary>
    /// 見つけているかの確認
    /// </summary>
    /// <returns>見つけていたらtrue そうでなければfalse</returns>
    bool IsFind(float playerPosX);

    // 検知できる範囲
    const float findRange = 160.0f;

    // 追跡速度
    const float trackSpeed = 10.0f;
};