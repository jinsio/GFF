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
    void MoveScroll(float deltaTime,VECTOR& plyPos);

    /// <summary>
    /// �X�N���[�����W�̃Q�b�^�[
    /// </summary>
    /// <returns>�X�N���[�����W</returns>
    VECTOR& GetScrPos() { return scrPos; }
    
    float GetscrRX() { return scrRX; }

    float GetScrSpeedLR() { return scrSpeedLR; }
    float GetScrSpeedXY() { return scrSpeedXY; }

    void SetScrLR(float plySpeed) { scrSpeedLR = plySpeed;}
    void SetScrXY(float plySpeed) { scrSpeedXY = plySpeed; }


private:
    float scrRX;        //�E�����փX�N���[��������W
    float scrRY;        //�������փX�N���[��������W
    float scrLX;        //�������փX�N���[��������W
    float scrLY;        //������փX�N���[��������W

    const float scrMaxW = 32*180;            //�E�����փX�N���[������ő���W
    const float scrMaxH = 32*40;            //�������փX�N���[������ő���W
    const float scrMinW = 0;                //�������փX�N���[������ŏ����W
    const float scrMinH = 0;                //������փX�N���[������ŏ����W

    VECTOR scrPos;     //�X�N���[�����W

    float scrSpeedLR;        //�X�N���[�����x
    float scrSpeedXY;        //�X�N���[�����x

    VECTOR scrSpeed;
    class Bullet;

};

