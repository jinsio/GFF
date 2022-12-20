#include "Button.h"

Button::Button()
    :tmppushP(FALSE)
    ,nowpushP(FALSE)
    ,tmppushI(FALSE)
    ,nowpushI(FALSE)
{
}

Button::~Button()
{
}

void Button::GetNowButtonP()
{
    if (CheckHitKey(KEY_INPUT_P))
    {
        nowpushP = TRUE;
    }
    else
    {
        nowpushP = FALSE;
    }
}

int Button::ButtonStatusP()
{
    GetNowButtonP();

    int ret = 0;

    //ボタンが押された瞬間
    if (tmppushP == FALSE && nowpushP == TRUE)
    {
        ret = 1;
    }

    //ボタンが長押しされている状態
    else if (tmppushP == TRUE && nowpushP == TRUE)
    {
        ret = 2;
    }

    //ボタンを離した瞬間
    else if (tmppushP == TRUE && nowpushP == FALSE)
    {
        ret = 3;
    }
    //ボタンが押されていない
   
    else {
        ret = 0;
    }
    tmppushP = nowpushP;
    return ret;
}

void Button::GetNowButtonI()
{
    if (CheckHitKey(KEY_INPUT_I))
    {
        nowpushI = TRUE;
    }
    else
    {
        nowpushI = FALSE;
    }
}

int Button::ButtonStatusI()
{
    GetNowButtonI();

    int tmp = 0;

    //ボタンが押された瞬間
    if (tmppushI == FALSE && nowpushI == TRUE)
    {
        tmp = 1;
    }

    //ボタンが長押しされている状態
    else if (tmppushI == TRUE && nowpushI == TRUE)
    {
        tmp = 2;
    }

    //ボタンを離した瞬間
    else if (tmppushI == TRUE && nowpushI == FALSE)
    {
        tmp = 3;
    }
    //ボタンが押されていない

    else {
        tmp = 0;
    }
    tmppushI = nowpushI;
    return tmp;
}
