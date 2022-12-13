#pragma once

#include "Monster.h"

/// <summary>
/// スライムクラス
/// </summary>
class Slime final : public Monster
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Slime();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Slime();

    /// <summary>
    /// スライムの更新処理
    /// </summary>
    /// <param name="deltaTime">1フレームの経過時間</param>
    void Update(float deltaTime) override;

private:
    /// <summary>
    /// 見つけているかの確認
    /// </summary>
    /// <returns>見つけていたらtrue そうでなければfalse</returns>
    bool IsFind(float playerPosX);

    // 自動移動秒数
    //float autoMoveCount;

    // 検知できる範囲
    const float findRange = 160.0f;

};