#include "Slime.h"

Slime::Slime()
{
    mPos= VGet(1920 / 2, 1080 / 2, 0);
    speed = 200.0f;
    mHandle = LoadGraph("assets/enemy/slime.png");
}

Slime::~Slime()
{
}

void Slime::Update(float deltaTime)
{
    // ������Ԃ̊m�F������
    CheckAlive();

    // ����ł��Ȃ����
    if (state != DEAD)
    {
        // �v���C���[�̍��W�������Ă���
        // GameObject* player = GetFirstGameObject(Player);

        // bool find=IsFind();
        bool find = false;

        // �v���C���[�������Ă�����
        if (find)
        {
            // �ǐՏ�ԂȂ�
            if (state == TRACK)
            {
                Track(deltaTime);
            }
            // �U����ԂȂ�
            else if (state == ATTACK)
            {
                Attack(deltaTime);
            }
        }
    }
}

void Slime::Track(float deltaTime)
{
    // �v���C���[��X���W���玩�g��X���W���������l�𐳋K�����đ��x�ƃf���^�^�C����������
}

void Slime::Attack(float deltaTime)
{
    // �U���̏���
    if (atkState == START)
    {

    }
    // �U���̍Œ�
    else if (atkState == NOW)
    {

    }
    // �U���̏I���
    else if (atkState == FINISH)
    {

    }
}

bool Slime::IsFind(float playerPosX)
{
    // �E�������Ă���ꍇ
    if (mRightDir)
    {
        // ���W�̍�����4�}�X�i160px�j��菬�������
        if (mPos.x - playerPosX > -findRange)
        {
            // �����Ă���ƕԂ�
            return true;
        }
    }
    // ���������Ă���ꍇ
    else
    {
        // ���W�̍�����4�}�X�i160px�j��菬�������
        if (mPos.x - playerPosX < findRange)
        {
            // �����Ă���ƕԂ�
            return true;
        }
    }
    
    // �����Ă��Ȃ��ƕԂ�
    return false;
}
