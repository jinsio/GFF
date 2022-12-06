#pragma once
#include "Monster.h"

class Golem : public Monster
{
public:
    /** コンストラクタ*/
    Golem();

    /** デストラクタ*/
    ~Golem();

    /** 更新*/
    void Update(float deltaTime) override;

private:
};