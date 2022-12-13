#pragma once
#include "DxLib.h"

const int CELL_WIDTH = 40;
const int CELL_HEIGHT = 40;
const int CELL_NUM_X = 162;
const int CELL_NUM_Y = 54;
class Map
{
public:
    Map();
    ~Map();
    void MapDraw();
    void SetScrPos(VECTOR& scrPos) { mapPos = scrPos; }
protected:
    struct sMapLayer
    {
        int GraphicHandle;
    };
    sMapLayer sMap[CELL_NUM_X][CELL_NUM_Y]={0};
    int chipgraphicHandle[(200/ 40) * (40 / 40)];
    VECTOR mapPos;
    int characterPack;
    int rawNum = 0;															//横方向のタイルナンバー
    int columnNum = 0;														//縦方向のタイルナンバー
    int num;																//タイルの番号
    char buffer[10];														//文字列変数
    bool eofFlag = false;													//eof（end of file）検出フラグ

};

