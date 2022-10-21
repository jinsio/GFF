#include "Collision.h"
#include"Player.h"

Player* player = new Player();

//-------------------------------------------------//
// @briaf   �R���X�g���N�^�[
//-------------------------------------------------//
Collision::Collision()
//.....�ϐ�������.....//
    :Marker(0)
    ,rawNum(0)
    ,columnNum(0)
    ,num(0)
    ,eofFlag(false)

{
    fopen_s(&fp, "MaouMapCollision.csv", "r");          //fopen_s�֐���csv�t�@�C����ǂݎ��`���ŊJ��
    if (fp = NULL)                                                            //fp����̎���
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
void Collision::ColBox()
{
    
}