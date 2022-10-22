#pragma once
#include "BaseMonster.h"

class Slime final : public BaseMonster
{
public:
    Slime();
    ~Slime();

    void Update(float deltaTime) override;
    void Draw() override;

private:
};
