#pragma once
#include "Monster.h"

class Skeleton final : public Monster
{
public:
    /** �R���X�g���N�^*/
    Skeleton();

    /** �f�X�g���N�^*/
    ~Skeleton();

    /** �X�V*/
    void Update(float deltaTime) override;

private:
};