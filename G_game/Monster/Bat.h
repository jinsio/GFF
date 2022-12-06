#pragma once
#include "Monster.h"

class Bat final : public Monster
{
public:
    /** コンストラクタ*/
    Bat();

    /** デストラクタ*/
    ~Bat();

    /** 更新*/
    void Update(float deltaTime) override;

private:
};