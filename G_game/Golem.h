#pragma once

#include "Monster.h"

/// <summary>
/// �S�[�����N���X
/// </summary>
class Golem : public Monster
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Golem();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Golem();

    /// <summary>
    /// �S�[�����̍X�V����
    /// </summary>
    /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
    void Update(float deltaTime) override;

private:
    /// <summary>
    /// �S�[�����̒ǐՏ���
    /// </summary>
    /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
    void Track(float deltaTime) override;

    /// <summary>
    /// �S�[�����̍U������
    /// </summary>
    /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
    void Attack(float deltaTime) override;

    /// <summary>
    /// �����Ă��邩�̊m�F
    /// </summary>
    /// <returns>�����Ă�����true �����łȂ����false</returns>
    bool IsFind(float playerPosX);

    // ���m�ł���͈�
    const float findRange = 160.0f;

    // �ǐՑ��x
    const float trackSpeed = 10.0f;
};