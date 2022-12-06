#pragma once
#include "Monster.h"

class Slime final : public Monster
{
public:
    /** コンストラクタ*/
    Slime();

    /** デストラクタ*/
    ~Slime();

    /** 更新*/
    void Update(float deltaTime) override;

private:
};