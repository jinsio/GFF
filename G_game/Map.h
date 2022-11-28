#pragma once
#include "DxLib.h"

const int CELL_WIDTH = 32;
const int CELL_HEIGHT = 32;
const int CELL_NUM_X = 120;
const int CELL_NUM_Y = 34;
class Map
{
public:
    Map();
    ~Map();
    void MapDraw();
    VECTOR& GetPosition() { return mPos; }
protected:
    struct sMapLayer
    {
        int GraphicHandle;
    };
    sMapLayer sMap[CELL_NUM_X][CELL_NUM_Y]={0};
    int chipgraphicHandle[(480/ 32) * (384 / 32)];
    VECTOR mPos;
    int characterPack;
    int rawNum = 0;															//�������̃^�C���i���o�[
    int columnNum = 0;														//�c�����̃^�C���i���o�[
    int num;																//�^�C���̔ԍ�
    char buffer[10];														//������ϐ�
    bool eofFlag = false;													//eof�iend of file�j���o�t���O

};

