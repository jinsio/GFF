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
    int rawNum = 0;															//�������̃^�C���i���o�[
    int columnNum = 0;														//�c�����̃^�C���i���o�[
    int num;																//�^�C���̔ԍ�
    char buffer[10];														//������ϐ�
    bool eofFlag = false;													//eof�iend of file�j���o�t���O

};

