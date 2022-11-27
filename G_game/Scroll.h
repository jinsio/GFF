#pragma once
#include<DxLib.h>

const float scrSpeed = 5.0f;

class Scroll
{
public:
    /// <summary>
    /// Scrollのコンストラクター
    /// </summary>
    Scroll();

    /// <summary>
    /// Scrollのデストラクター
    /// </summary>
    ~Scroll();

    /// <summary>
    /// スクロール処理
    /// </summary>
    /// <param name="plyPos">プレイヤーポジション</param>
    /// <param name="mapPos">マップポジション</param>
    void MoveScroll(VECTOR& plyPos,VECTOR& mapPos);


private:
    float scrRX;
    float scrRY;
    float scrLX;
    float scrLY;

    float scrMaxW;
    float scrMaxH;
    float scrMinW;
    float scrMinH;


};

