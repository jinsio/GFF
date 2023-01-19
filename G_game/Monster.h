#pragma once

#include "DxLib.h"
#include "monsterInfo.h"
#include "GameObject.h"

/// <summary>
/// �����X�^�[�N���X
/// </summary>
class Monster : public GameObject
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Monster();

    /// <summary>
    /// ���z�f�X�g���N�^
    /// </summary>
    virtual ~Monster();

protected:
    // �傫��
    VECTOR scale = { 0 };

    // �傫���i�����j
    VECTOR halfScale = { 0 };

    // ���x
    float speed;

    // �ړ��A�j���[�V����
    int moveAnim[4] = { -1 };

    // �U���A�j���[�V����
    int attackAnim[4] = { -1 };

    // ��e�A�j���[�V����
    int damageAnim[2] = { -1 };

    // ���g�̏��
    int state;

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

    // �U���̏��
    int atkState;

    // �̗�
    int hp;

    /// <summary>
    /// ������Ԃ̊m�F
    /// </summary>
    void CheckAlive();

    /// <summary>
    /// �ǐՏ���
    /// </summary>
    virtual void Track(float deltaTime) {};

    /// <summary>
    /// �U������
    /// </summary>
    virtual void  Attack(float deltaTime) {};

};