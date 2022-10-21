#pragma once
#include "monsterInfo.h"

class BaseMonster
{
public:
    BaseMonster();
    virtual ~BaseMonster();

    struct vec2
    {
        float x;
        float y;
    };

    virtual void Update(float deltaTime) = 0;
    virtual void Draw();

protected:

    //! �ʒu
    vec2 pos;

    //! �傫��
    vec2 scale;

    //! �傫���i�����j
    vec2 halfScale;

    //! ���x
    float speed;

    //! �\���p
    int displayImage;

    //! �ړ��A�j���[�V�����摜
    int moveAnim[moveAnimNum] = { -1 };

    //! �U���A�j���[�V�����摜
    int attackAnim[attackAnimNum] = { -1 };

    //! ��e�A�j���[�V�����摜
    int damageAnim[damageAnimNum] = { -1 };

    //! �̗�
    int hp;

    //! �����Ă��邩�ǂ���
    bool isAlive;

    //! �������ǂ���
    bool isAlly;

    //! �E�������ǂ���
    bool isDirRight;

    //! tmp
    int i;
};
