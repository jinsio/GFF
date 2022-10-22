#pragma once
#include "BaseMonster.h"

class Bat final : public BaseMonster
{
public:
    Bat();
    ~Bat();

    void Update(float deltaTime) override;
    void Draw() override;

private:
};
