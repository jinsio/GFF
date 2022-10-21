#pragma once
#include"DxLib.h"

//.....定数宣言.....//
const int CELL_WIDTH = 36;                  //当たり判定の幅
const int CELL_HEIGHT = 36;                 //当たり判定の高さ
const int CELL_NUM_X = 120;                 //当たり判定の横の数
const int CELL_NUM_Y = 34;                  //当たり判定の縦の数

class Collision
{
//.....関数宣言.....//
public:
    Collision();                            //コンストラクター
    ~Collision();                           //デストラクター

    void ColBox();

    int SetPosition(int num1, int num2) { return num1 + num2; }
private:
    struct sColLayer
    {
        int BoxHandle;
    };
    sColLayer sCol[CELL_NUM_X][CELL_NUM_Y]={0};
    int colBoxHandle[2];                    //当たり判定の種類
    int Marker;                             //文字を格納する変数
    int rawNum;                             //横方向のタイルナンバー
    int columnNum;                          //縦方向のタイルナンバー
    int num;                                //当たり判定の番号
    char buffer[10];                        //文字列変数
    bool eofFlag;                           //eof（end of file）検出フラグ
    FILE* fp;                               //ファイルポインター
    VECTOR mBox;
};

