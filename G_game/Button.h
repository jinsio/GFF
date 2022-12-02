#pragma once

#include "DxLib.h"
class Button
{
public:
    Button();
    ~Button();

    void GetNowButton();
    int  ButtonStatus();

private:
    bool tmppush;
    bool nowpush;
};

