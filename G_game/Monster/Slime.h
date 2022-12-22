#pragma once

#include "Monster.h"

/// <summary>
/// �X���C���N���X
/// </summary>
class Slime final : public Monster
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Slime();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Slime();

    /// <summary>
    /// �X���C���̍X�V����
    /// </summary>
    /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
    void Update(float deltaTime) override;

private:
    /// <summary>
    /// �X���C���̒ǐՏ���
    /// </summary>
    /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
    void Track(float deltaTime) override;

    /// <summary>
    /// �X���C���̍U������
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