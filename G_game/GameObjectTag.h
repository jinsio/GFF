#pragma once
#include <vector>

// ゲーム内アクター・当たり判定の種類別タグ
// 必要なものはBeginとEndの間に254個まで定義できる
enum class GameObjectTag : unsigned char
{
    Player,
    Bullet,
    ShotDummy,
    Enemy,
    Map,
};

//------------------------------------------------------------------------------------
// @brief ループ制御用。上記タグの全要素を記述しておくこと.
// @detail 使用法として,for( ObjectTag &tag : ObjectTagAll ) とすることで、
// 全Tag要素のループにできる
//------------------------------------------------------------------------------------
constexpr static GameObjectTag ObjectTagAll[] =
{
    GameObjectTag::Player,
    GameObjectTag::Bullet,
    GameObjectTag::ShotDummy,
    GameObjectTag::Enemy,
    GameObjectTag::Map,
};