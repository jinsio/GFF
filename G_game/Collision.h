#pragma once
#include"DxLib.h"


//.....定数宣言.....//
const int BOX_WIDTH = 32;                  //当たり判定の幅
const int BOX_HEIGHT = 32;                 //当たり判定の高さ
const int BOX_NUM_X = 240;                 //当たり判定の横の数
const int BOX_NUM_Y = 66;                  //当たり判定の縦の数


class Collision
{


    //.....関数宣言.....//
public:
    /// <summary>
    /// コンストラクタ―
    /// </summary>
    Collision();

    /// <summary>
    /// デストラクタ―
    /// </summary>
    ~Collision();

    /// <summary>
    /// 当たり判定更新処理
    /// </summary>
    /// <param name="objpos"></param>
    bool ColBox(VECTOR& objpos);

    /// <summary>
    /// 当たり判定座標のセッター
    /// </summary>
    /// <param name="scrPos">スクロール座標</param>
    void SetScrPos(VECTOR& scrPos) { colPos = scrPos; }

private:
    struct sColLayer
    {
        int BoxHandle;
    };
    sColLayer sCol[BOX_NUM_X][BOX_NUM_Y] = { 0 };
    int colBoxHandle[2];                    //当たり判定の種類
    int Marker;                             //文字を格納する変数
    int rawNum;                             //横方向のタイルナンバー
    int columnNum;                          //縦方向のタイルナンバー
    int num;                                //当たり判定の番号
    char buffer[10];                        //文字列変数
    bool eofFlag;                           //eof（end of file）検出フラグ
    FILE* fp;                               //ファイルポインター

    bool isStand;                           //地面に立っているかどうか
    VECTOR colPos;                          //当たり判定座標
};

