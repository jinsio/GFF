#pragma once
#include "Monster.h"

class Slime final : public Monster
{
public:
    /** �R���X�g���N�^*/
    Slime();

    /** �f�X�g���N�^*/
    ~Slime();

    /** �X�V*/
    void Update(float deltaTime) override;

private:
};