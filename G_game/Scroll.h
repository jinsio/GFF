#pragma once
#include<DxLib.h>

const float scrSpeed = 5.0f;        //スクロール速度

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

    VECTOR& GetScrPos();
private:
    float scrRX;        //右方向へスクロールする座標
    float scrRY;        //下方向へスクロールする座標
    float scrLX;        //左方向へスクロールする座標
    float scrLY;        //上方向へスクロールする座標

    float scrMaxW;      //右方向へスクロールする最大座標
    float scrMaxH;      //下方向へスクロールする最大座標
    float scrMinW;      //左方向へスクロールする最大座標
    float scrMinH;      //上方向へスクロールする最大座標


};

