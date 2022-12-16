#include "Slime.h"

Slime::Slime()
{
}

Slime::~Slime()
{
}

void Slime::Update(float deltaTime)
{
    // 生死状態の確認をする
    CheckAlive();

    // プレイヤーの座標を持ってくる
    // class Player* player = Getter();
    float tmp = 0.0f;
    bool find = IsFind(tmp);

    // プレイヤーを見つけていたら
    if (find)
    {
        // 近づく

    }
    // プレイヤーを見つけていなければ
    else
    {
        // 左右に動く的な

        if (dirRight)
        {
            // x方向のべクトルをプラスに
        }
        else
        {
            // x方向のベクトルをマイナスに
        }
    }

}

bool Slime::IsFind(float playerPosX)
{
    // 右を向いている場合
    if (dirRight)
    {
        // 座標の差分が4マス（160px）より小さければ
        if (pos.x - playerPosX > -findRange)
        {
            // 見つけていると返す
            return true;
        }
    }
    // 左を向いている場合
    else
    {
        // 座標の差分が4マス（160px）より小さければ
        if (pos.x - playerPosX < findRange)
        {
            // 見つけていると返す
            return true;
        }
    }
    
    // 見つけていないと返す
    return false;
}
