#pragma once
#include "monsterInfo.h"

class Monster
{
public:
    /** �R���X�g���N�^*/
    Monster();

    /** ���z�f�X�g���N�^*/
    virtual ~Monster();

    /** �X�V�i�������z�֐��j*/
    virtual void Update(float deltaTime) = 0;

    /** �`��i���z�֐��j*/
    void Draw();

    /** �����Ă��邩�ǂ����̎擾*/
    bool GetAlive() { return isAlive; }

protected:
    /** ���W*/
    VECTOR pos = { 0 };

    /** �傫��*/
    VECTOR scale = { 0 };

    /** �傫���i�����j*/
    VECTOR halfScale = { 0 };

    /** ���x*/
    float speed;
    
    /** �d��*/
    float gravity;

    /** �`��p*/
    int handle;

    /** �ړ��A�j���[�V����*/
    int moveAnim[moveAnimNum] = { -1 };

    /** �U���A�j���[�V����*/
    int attackAnim[attackAnimNum] = { -1 };

    /** ��e�A�j���[�V����*/
    int damageAnim[damageAnimNum] = { -1 };

    /** �̗�*/
    int hp;

    /** �����Ă��邩�ǂ���*/
    bool isAlive;

    /** �������ǂ���*/
    bool isAlly;

    /** �E�������ǂ���*/
    bool isDirRight;

    //! tmp
    int i;
};