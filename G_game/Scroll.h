#pragma once
#include<DxLib.h>

const float scrSpeed = 5.0f;

class Scroll
{
public:
    /// <summary>
    /// Scroll�̃R���X�g���N�^�[
    /// </summary>
    Scroll();

    /// <summary>
    /// Scroll�̃f�X�g���N�^�[
    /// </summary>
    ~Scroll();

    /// <summary>
    /// �X�N���[������
    /// </summary>
    /// <param name="plyPos">�v���C���[�|�W�V����</param>
    /// <param name="mapPos">�}�b�v�|�W�V����</param>
    void MoveScroll(VECTOR& plyPos,VECTOR& mapPos);


private:
    float scrRX;
    float scrRY;
    float scrLX;
    float scrLY;

    float scrMaxW;
    float scrMaxH;
    float scrMinW;
    float scrMinH;


};

