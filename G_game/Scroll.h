#pragma once
#include<DxLib.h>

const float scrSpeed = 5.0f;

class Scroll
{
public:
    Scroll();
    ~Scroll();
    void Update();
private:
    float scrX;
    float scrY;
    float scrW;
    float scrH;

};

