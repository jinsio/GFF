#include "Button.h"

Button::Button()
    :tmppush(FALSE)
    ,nowpush(FALSE)
{
}

Button::~Button()
{
}

void Button::GetNowButton()
{
    if (CheckHitKey(KEY_INPUT_P))
    {
        nowpush = TRUE;
    }
    else
    {
        nowpush = FALSE;
    }
}

int Button::ButtonStatus()
{
    GetNowButton();

    int ret = 0;

    //ボタンが押された瞬間
    if (tmppush == FALSE && nowpush == TRUE)
    {
        ret = 1;
    }

    //ボタンが長押しされている状態
    else if (tmppush == TRUE && nowpush == TRUE)
    {
        ret = 2;
    }

    //ボタンを離した瞬間
    else if (tmppush == TRUE && nowpush == FALSE)
    {
        ret = 3;
    }
    //ボタンが押されていない
   
    else {
        ret = 0;
    }
    tmppush = nowpush;
    return ret;
}
