#pragma once
#include<DxLib.h>


/*Scroll�̃N���X*/
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
    void Update(float deltaTime,VECTOR& plyPos);

    /// <summary>
    /// �X�N���[���̕`��I�t�Z�b�gX���擾
    /// </summary>
    /// <returns>X�����I�t�Z�b�g</returns>
    int GetDrawOffSetX();

    /// <summary>
    /// �X�N���[���̕`��I�t�Z�b�gY���擾
    /// </summary>
    /// <returns>Y�����I�t�Z�b�g</returns>
    int GetDrawOffSetY();

private:
    float scrollX;        //�X�N���[��X
    float scrollY;        //�X�N���[��Y

    const float scrMaxW = 1920/40*20;            //�E�����փX�N���[���J�n�ő���W
    const float scrMaxH = 1080/40*25;            //�������փX�N���[���J�n�ő���W
    const float scrMinW = 1920/40*15;            //�������փX�N���[���J�n�ŏ����W
    const float scrMinH = 1080/40*15;            //������փX�N���[���J�n�ŏ����W

    float sclMaxX;                               //X�����X�N���[���ő�l
    float sclMaxY;                               //Y�����X�N���[���ő�l
    float sclMinX;                               //X�����X�N���[���ŏ��l
    float sclMinY;                               //Y�����X�N���[���ŏ��l

    float dx, dy;                                //�����߂����W

    class Bullet;

};

