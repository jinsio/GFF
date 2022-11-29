#pragma once
#include<DxLib.h>

const float scrSpeed = 5.0f;        //�X�N���[�����x

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

    VECTOR& GetScrPos();
private:
    float scrRX;        //�E�����փX�N���[��������W
    float scrRY;        //�������փX�N���[��������W
    float scrLX;        //�������փX�N���[��������W
    float scrLY;        //������փX�N���[��������W

    float scrMaxW;      //�E�����փX�N���[������ő���W
    float scrMaxH;      //�������փX�N���[������ő���W
    float scrMinW;      //�������փX�N���[������ő���W
    float scrMinH;      //������փX�N���[������ő���W


};

