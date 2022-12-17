#pragma once
#include<DxLib.h>


/*Scrollのクラス*/
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
    void Update(float deltaTime,VECTOR& plyPos);

    /// <summary>
    /// スクロールの描画オフセットXを取得
    /// </summary>
    /// <returns>X方向オフセット</returns>
    int GetDrawOffSetX();

    /// <summary>
    /// スクロールの描画オフセットYを取得
    /// </summary>
    /// <returns>Y方向オフセット</returns>
    int GetDrawOffSetY();

private:
    float scrollX;        //スクロールX
    float scrollY;        //スクロールY

    const float scrMaxW = 1920/40*20;            //右方向へスクロール開始最大座標
    const float scrMaxH = 1080/40*25;            //下方向へスクロール開始最大座標
    const float scrMinW = 1920/40*15;            //左方向へスクロール開始最小座標
    const float scrMinH = 1080/40*15;            //上方向へスクロール開始最小座標

    float sclMaxX;                               //X方向スクロール最大値
    float sclMaxY;                               //Y方向スクロール最大値
    float sclMinX;                               //X方向スクロール最小値
    float sclMinY;                               //Y方向スクロール最小値

    float dx, dy;                                //押し戻し座標

    class Bullet;

};

