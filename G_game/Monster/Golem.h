#pragma once
#include "Monster.h"

class Golem : public Monster
{
public:
    /** �R���X�g���N�^*/
    Golem();

    /** �f�X�g���N�^*/
    ~Golem();

    /** �X�V*/
    void Update(float deltaTime) override;

private:
};