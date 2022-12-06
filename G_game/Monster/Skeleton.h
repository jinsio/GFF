#pragma once
#include "Monster.h"

class Skeleton final : public Monster
{
public:
    /** コンストラクタ*/
    Skeleton();

    /** デストラクタ*/
    ~Skeleton();

    /** 更新*/
    void Update(float deltaTime) override;

private:
};