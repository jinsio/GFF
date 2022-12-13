#pragma once

#include "monsterInfo.h"

/// <summary>
/// �����X�^�[�N���X
/// </summary>
class Monster
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

    /// <summary>
    /// �����X�^�[�̍X�V�i�������z�֐��j
    /// </summary>
    /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
    virtual void Update(float deltaTime) = 0;

    /// <summary>
    /// �����X�^�[�̕`��
    /// </summary>
    void Draw();

    /// <summary>
    /// ������Ԃ̎擾
    /// </summary>
    /// <returns>�����Ă����true ����ł�����false</returns>
    bool GetAlive() { return alive; }

protected:
    // ���W
    VECTOR pos = { 0 };

    // �傫��
    VECTOR scale = { 0 };

    // �傫���i�����j
    VECTOR halfScale = { 0 };

    // ���x
    float speed;
    
    // �d��
    float gravity;

    // �`��n���h��
    int handle;

    // �ړ��A�j���[�V����
    int moveAnim[moveAnimNum] = { -1 };

    // �U���A�j���[�V����
    int attackAnim[attackAnimNum] = { -1 };

    // ��e�A�j���[�V����
    int damageAnim[damageAnimNum] = { -1 };

    // �̗�
    int hp;

    // �������
    bool alive;

    // �E�������Ă��邩
    bool dirRight;

    /// <summary>
    /// ������Ԃ̊m�F
    /// </summary>
    void CheckAlive();

};