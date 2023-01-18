#pragma once
#include"DxLib.h"


//.....�萔�錾.....//
const int BOX_WIDTH = 40;                  //�����蔻��̕�
const int BOX_HEIGHT = 40;                 //�����蔻��̍���
const int BOX_NUM_X = 162;                 //�����蔻��̉��̐�
const int BOX_NUM_Y = 54;                  //�����蔻��̏c�̐�


class Collision
{

public:
    /// <summary>
    /// �R���X�g���N�^�\
    /// </summary>
    Collision();

    /// <summary>
    /// �f�X�g���N�^�\
    /// </summary>
    ~Collision();


private:
    struct sColLayer
    {
        int BoxHandle;
    };
    sColLayer sCol[BOX_NUM_X][BOX_NUM_Y] = { 0 };
    int colBoxHandle[5];                                //�����蔻��̎��
    int Marker;                                         //�������i�[����ϐ�
    int rawNum;                                         //�������̃^�C���i���o�[
    int columnNum;                                      //�c�����̃^�C���i���o�[
    int num;                                            //�����蔻��̔ԍ�
    char buffer[10];                                    //������ϐ�
    bool eofFlag;                                       //eof�iend of file�j���o�t���O
    FILE* fp;                                           //�t�@�C���|�C���^�[

    //����(�X�P���g��)�u���b�N�t���O
    bool VisionFlag = false;

};

/// <summary>
/// Block�\����
/// </summary>
struct Block
{
    /// <summary>
    /// �R���X�g���N�^�[
    /// </summary>
    Block(const VECTOR& size, const VECTOR& pos);

    /// <summary>
    /// Block�ړ�����
    /// </summary>
    void Move();

    VECTOR mSize;
    VECTOR localPos;
    VECTOR worldPos;
    int boxHandle[5];
};

/// <summary>
/// Model�\����
/// </summary>
struct Model
{

    Model(const VECTOR& size, const VECTOR& pos);
    void Move();

    VECTOR mSize;
    VECTOR localPos;
    VECTOR worldPos;
};

/// <summary>
/// �����蔻��
/// </summary>
bool ColBox(const Model& model, const Block& block);