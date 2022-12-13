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
    void MoveScroll(float deltaTime,VECTOR& plyPos);

    /// <summary>
    /// スクロール座標のゲッター
    /// </summary>
    /// <returns>スクロール座標</returns>
    VECTOR& GetScrPos() { return scrPos; }
    
    float GetscrRX() { return scrRX; }

    float GetScrSpeedLR() { return scrSpeedLR; }
    float GetScrSpeedXY() { return scrSpeedXY; }

    void SetScrLR(float plySpeed) { scrSpeedLR = plySpeed;}
    void SetScrXY(float plySpeed) { scrSpeedXY = plySpeed; }


private:
    float scrRX;        //右方向へスクロールする座標
    float scrRY;        //下方向へスクロールする座標
    float scrLX;        //左方向へスクロールする座標
    float scrLY;        //上方向へスクロールする座標

    const float scrMaxW = 32*180;            //右方向へスクロールする最大座標
    const float scrMaxH = 32*40;            //下方向へスクロールする最大座標
    const float scrMinW = 0;                //左方向へスクロールする最小座標
    const float scrMinH = 0;                //上方向へスクロールする最小座標

    VECTOR scrPos;     //スクロール座標

    float scrSpeedLR;        //スクロール速度
    float scrSpeedXY;        //スクロール速度

    VECTOR scrSpeed;
    class Bullet;

};

