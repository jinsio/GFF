#include "Slime.h"

Slime::Slime()
{
    mPos= VGet(1920 / 2, 1080 / 2, 0);
    speed = 200.0f;
    mHandle = LoadGraph("assets/enemy/slime.png");
}

Slime::~Slime()
{
}

void Slime::Update(float deltaTime)
{
    // 生死状態の確認をする
    CheckAlive();

    // 死んでいなければ
    if (state != DEAD)
    {
        // プレイヤーの座標を持ってくる
        // GameObject* player = GetFirstGameObject(Player);

        // bool find=IsFind();
        bool find = false;

        // プレイヤーを見つけていたら
        if (find)
        {
            // 追跡状態なら
            if (state == TRACK)
            {
                Track(deltaTime);
            }
            // 攻撃状態なら
            else if (state == ATTACK)
            {
                Attack(deltaTime);
            }
        }
    }
}

void Slime::Track(float deltaTime)
{
    // プレイヤーのX座標から自身のX座標を引いた値を正規化して速度とデルタタイムをかける
}

void Slime::Attack(float deltaTime)
{
    // 攻撃の初動
    if (atkState == START)
    {

    }
    // 攻撃の最中
    else if (atkState == NOW)
    {

    }
    // 攻撃の終わり
    else if (atkState == FINISH)
    {

    }
}

bool Slime::IsFind(float playerPosX)
{
    // 右を向いている場合
    if (mRightDir)
    {
        // 座標の差分が4マス（160px）より小さければ
        if (mPos.x - playerPosX > -findRange)
        {
            // 見つけていると返す
            return true;
        }
    }
    // 左を向いている場合
    else
    {
        // 座標の差分が4マス（160px）より小さければ
        if (mPos.x - playerPosX < findRange)
        {
            // 見つけていると返す
            return true;
        }
    }
    
    // 見つけていないと返す
    return false;
}
