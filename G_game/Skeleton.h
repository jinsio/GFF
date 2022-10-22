#pragma once
#include "BaseMonster.h"

class Skeleton final : public BaseMonster
{
public:
    Skeleton();
    ~Skeleton();

    void Update(float deltaTime) override;
    void Draw() override;

private:
};
