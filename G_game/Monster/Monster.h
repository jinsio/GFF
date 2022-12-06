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

protected:
    /** ���W*/
    vec2 pos = { 0 };

    /** �傫��*/
    vec2 scale = { 0 };

    /** �傫���i�����j*/
    vec2 halfScale = { 0 };

    /** ���x*/
    float speed;
    
    /** �d��*/
    float gravity;

    /** �`��p*/
    int displayImage;

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