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

    /// <summary>
    /// �����蔻��
    /// </summary>
    bool ColBox(const struct Model& model, const struct Block& block);

    bool ColHitPair(const struct Block& block, int i, int j, int colTyoe);
    bool ColHitPair(const struct Model& model, const struct Model& model2);
    bool ColHitPair(const Block& block, const Block& block2, int i, int j);

    VECTOR CalcPushBack(int i, int j, int colType);
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

    int bx, by;
    bool isGround;
    VECTOR pushBack;
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
    Block(const VECTOR& pos);

    /// <summary>
    /// Block�ړ�����
    /// </summary>
    void Move(VECTOR& pos);

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
    void Move(VECTOR& pos);

    VECTOR mSize;
    VECTOR localPos;
    VECTOR worldPos;
};
