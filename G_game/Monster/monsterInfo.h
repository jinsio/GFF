#pragma once
//------------------------------------------------------------------------------------------------//
// @brief �萔�錾
//------------------------------------------------------------------------------------------------//

// �ړ��A�j���[�V������
const int moveAnimNum = 4;

// �U���A�j���[�V������
const int attackAnimNum = 4;

// ��e�A�j���[�V������
const int damageAnimNum = 2;

// ��Ԃ̗�
enum State
{
    IDLE = 0,  // �ҋ@
    TRACK,     // �ǐ�
    ATTACK,    // �U��
    DEAD,      // ���S
};

enum AtkState
{
    START = 0,  // �U���J�n
    NOW,        // �Œ�
    FINISH,     // �U���I��
};