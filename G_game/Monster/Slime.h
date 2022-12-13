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
    /// �����Ă��邩�̊m�F
    /// </summary>
    /// <returns>�����Ă�����true �����łȂ����false</returns>
    bool IsFind(float playerPosX);

    // �����ړ��b��
    //float autoMoveCount;

    // ���m�ł���͈�
    const float findRange = 160.0f;

};