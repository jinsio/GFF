#include "Slime.h"

Slime::Slime()
{
}

Slime::~Slime()
{
}

void Slime::Update(float deltaTime)
{
    // ������Ԃ̊m�F������
    CheckAlive();

    // �v���C���[�̍��W�������Ă���
    // class Player* player = Getter();
    float tmp = 0.0f;
    bool find = IsFind(tmp);

    // �v���C���[�������Ă�����
    if (find)
    {
        // �߂Â�

    }
    // �v���C���[�������Ă��Ȃ����
    else
    {
        // ���E�ɓ����I��

        if (dirRight)
        {
            // x�����̂׃N�g�����v���X��
        }
        else
        {
            // x�����̃x�N�g�����}�C�i�X��
        }
    }

}

bool Slime::IsFind(float playerPosX)
{
    // �E�������Ă���ꍇ
    if (dirRight)
    {
        // ���W�̍�����4�}�X�i160px�j��菬�������
        if (pos.x - playerPosX > -findRange)
        {
            // �����Ă���ƕԂ�
            return true;
        }
    }
    // ���������Ă���ꍇ
    else
    {
        // ���W�̍�����4�}�X�i160px�j��菬�������
        if (pos.x - playerPosX < findRange)
        {
            // �����Ă���ƕԂ�
            return true;
        }
    }
    
    // �����Ă��Ȃ��ƕԂ�
    return false;
}
