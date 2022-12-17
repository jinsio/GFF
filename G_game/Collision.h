#pragma once
#include"DxLib.h"


//.....定数宣言.....//
const int BOX_WIDTH = 40;                  //当たり判定の幅
const int BOX_HEIGHT = 40;                 //当たり判定の高さ
const int BOX_NUM_X = 162;                 //当たり判定の横の数
const int BOX_NUM_Y = 54;                  //当たり判定の縦の数


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
    /// 当たり判定
    /// </summary>
    bool ColBox(VECTOR& objPos);


private:
    struct sColLayer
    {
        int BoxHandle;
    };
    sColLayer sCol[BOX_NUM_X][BOX_NUM_Y] = { 0 };
    int colBoxHandle[5];                    //当たり判定の種類
    int Marker;                             //文字を格納する変数
    int rawNum;                             //横方向のタイルナンバー
    int columnNum;                          //縦方向のタイルナンバー
    int num;                                //当たり判定の番号
    char buffer[10];                        //文字列変数
    bool eofFlag;                           //eof（end of file）検出フラグ
    FILE* fp;                               //ファイルポインター

    //透明(スケルトン)ブロックフラグ
    bool VisionFlag = false;

};

