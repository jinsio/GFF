#pragma once
#include"DxLib.h"

//.....�萔�錾.....//
const int BOX_WIDTH = 32;                  //�����蔻��̕�
const int BOX_HEIGHT = 32;                 //�����蔻��̍���
const int BOX_NUM_X = 120;                 //�����蔻��̉��̐�
const int BOX_NUM_Y = 34;                  //�����蔻��̏c�̐�

class Collision
{
//.....�֐��錾.....//
public:
    Collision();                            //�R���X�g���N�^�[
    ~Collision();                           //�f�X�g���N�^�[

    bool ColBox(VECTOR& objpos);

private:
    struct sColLayer
    {
        int BoxHandle;
    };
    sColLayer sCol[BOX_NUM_X][BOX_NUM_Y]={0};
    int colBoxHandle[2];                    //�����蔻��̎��
    int Marker;                             //�������i�[����ϐ�
    int rawNum;                             //�������̃^�C���i���o�[
    int columnNum;                          //�c�����̃^�C���i���o�[
    int num;                                //�����蔻��̔ԍ�
    char buffer[10];                        //������ϐ�
    bool eofFlag;                           //eof�iend of file�j���o�t���O
    FILE* fp;                               //�t�@�C���|�C���^�[

    struct collisionBox
    {
        VECTOR left;
        VECTOR right;
    }colBox;
    VECTOR pb;
};

