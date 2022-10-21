#pragma once
#include"DxLib.h"

//.....�萔�錾.....//
const int CELL_WIDTH = 36;                  //�����蔻��̕�
const int CELL_HEIGHT = 36;                 //�����蔻��̍���
const int CELL_NUM_X = 120;                 //�����蔻��̉��̐�
const int CELL_NUM_Y = 34;                  //�����蔻��̏c�̐�

class Collision
{
//.....�֐��錾.....//
public:
    Collision();                            //�R���X�g���N�^�[
    ~Collision();                           //�f�X�g���N�^�[

    void ColBox();

    int SetPosition(int num1, int num2) { return num1 + num2; }
private:
    struct sColLayer
    {
        int BoxHandle;
    };
    sColLayer sCol[CELL_NUM_X][CELL_NUM_Y]={0};
    int colBoxHandle[2];                    //�����蔻��̎��
    int Marker;                             //�������i�[����ϐ�
    int rawNum;                             //�������̃^�C���i���o�[
    int columnNum;                          //�c�����̃^�C���i���o�[
    int num;                                //�����蔻��̔ԍ�
    char buffer[10];                        //������ϐ�
    bool eofFlag;                           //eof�iend of file�j���o�t���O
    FILE* fp;                               //�t�@�C���|�C���^�[
    VECTOR mBox;
};

