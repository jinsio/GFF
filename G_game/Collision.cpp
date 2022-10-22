#include "Collision.h"
#include"Player.h"
#include <math.h>

Player* player = new Player();

//-------------------------------------------------//
// @briaf   �R���X�g���N�^�[
//-------------------------------------------------//
Collision::Collision()
//.....�ϐ�������.....//
    :Marker(0)
    , rawNum(0)
    , columnNum(0)
    , num(0)
    , eofFlag(false)
    , fp(NULL)
{
    fopen_s(&fp, "assets/map/MaouMapCollision.csv", "r");          //fopen_s�֐���csv�t�@�C����ǂݎ��`���ŊJ��
    if (fp == NULL)                                                            //fp����̎���
    {
        DebugBreak();                                                         //�f�o�b�O���~
    }
    memset(buffer, 0, sizeof(buffer));                        //memset�֐��Ń�������buffer���Z�b�g�Asizeof���Z�q�ŗv�f�������߂�

    while (eofFlag)
    {
        while (eofFlag)
        {
            Marker = fgetc(fp);                                        //fp���當����ǂ��Marker�Ɋi�[
            if (Marker == EOF)eofFlag = true;                                 //EOF�����o������t���O�𗧂Ă�

            if (Marker != ','&& Marker != '\n')                               //��؂艻���s�łȂ����
            {
                strcat_s(buffer, (const char*)Marker);    //buffer�ɘA�����āAconst char�֐��ŏ���������
            }
            else
            {
                num = atoi(buffer);                                    //buffer��int�^�ɒ�����num�ɑ��
                sCol[columnNum][rawNum].BoxHandle = colBoxHandle[num];        //num�ԍ��̃n���h�����擾
                memset(buffer, 0, sizeof(buffer));            //memset�֐��Ń�������buffer���Z�b�g�Asizeof���Z�q�ŗv�f�������߂�
                break;                                                        //��؂肩���s�Ȃ̂Ń��[�v�Ŕ�����
            }
        }
        Marker = ',' ? columnNum++ : rawNum++, columnNum = 0;                 //��؂�͗�𑝂₵�A���s�͍s�𑝂₵�ė��0�ɂ���
    }
    fclose(fp);                                                       //�t�@�C�������
}

//-------------------------------------------------//
// @briaf   �f�X�g���N�^�[
//-------------------------------------------------//
Collision::~Collision()
{
}

//-------------------------------------------------//
// @briaf   �����蔻��
//-------------------------------------------------//
bool Collision::ColBox(VECTOR& objPos)
{
    //�I�u�W�F�N�gBOX�̒��_���W//
    int objLX = (objPos.x - XSize)/BOX_WIDTH;
    int objLY = (objPos.y - YSize) / BOX_HEIGHT;
    int objRX = (objPos.x + XSize) / BOX_WIDTH;
    int objRY = (objPos.y + YSize) / BOX_HEIGHT;


    for (int iy = objLY ; iy < objRY; iy++)
    {
        for (int jx = objLX; jx < objRX; jx++)
        {
            //�����蔻��BOX�̒��_���W//
            colBox.left.x = jx * BOX_WIDTH;
            colBox.left.y = iy * BOX_HEIGHT;
            colBox.right.x = colBox.left.x + BOX_WIDTH;
            colBox.right.y = colBox.left.y + BOX_HEIGHT;

            //�Փ˂����ۂ̉����߂�����//
            int pbX1 = colBox.left.x - (objPos.x - XSize);
            int pbX2 = colBox.right.x -(objPos.y - YSize);
            int pbY1 = colBox.left.y - (objPos.x + XSize);
            int pbY2 = colBox.right.y -(objPos.y + YSize);

            pb.x = (abs(pbX1) < abs(pbX2)) ? pbX1 : pbX2;
            pb.y = (abs(pbY1) < abs(pbY2)) ? pbY1 : pbY2;

            if (sCol[jx][iy].BoxHandle = colBoxHandle[1])                //�u���b�N�ɓ���������
            {
                abs((int)pb.x) < abs((int)pb.y) ? objPos.x += pb.x : objPos.y += pb.y;  //�����߂�
                return true;                                            //�u���b�N�ɓ������Ă���Ƃ����Ӗ���true��Ԃ�
            }
            else                                                         //�u���b�N�ɓ������Ă��Ȃ�������
            {
                return false;                                           //�u���b�N�ɓ������Ă��Ȃ��Ƃ����Ӗ���false��Ԃ�
            }
        }
    }
}