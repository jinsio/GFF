#pragma once
#include "BaseMonster.h"

class Orc final : public BaseMonster
{
public:
    Orc();
    ~Orc();

    void Update(float deltaTime) override;
    void Draw() override;

private:
};
