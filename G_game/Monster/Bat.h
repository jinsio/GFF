#pragma once
#include "Monster.h"

class Bat final : public Monster
{
public:
    /** �R���X�g���N�^*/
    Bat();

    /** �f�X�g���N�^*/
    ~Bat();

    /** �X�V*/
    void Update(float deltaTime) override;

private:
};