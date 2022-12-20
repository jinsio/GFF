#pragma once

#include "DxLib.h"
class Button
{
public:
    Button();
    ~Button();

    void GetNowButtonP();
    int  ButtonStatusP();

    void GetNowButtonI();
    int  ButtonStatusI();
private:
    bool tmppushP;
    bool nowpushP;
    bool tmppushI;
    bool nowpushI;
};

