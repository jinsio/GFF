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
 

    //ボタンが押された瞬間
    if (tmppush == FALSE && nowpush == TRUE)
    {
        tmppush = nowpush;
        return 1;
    }

    //ボタンが長押しされている状態
    else if (tmppush == TRUE && nowpush == TRUE)
    {
        tmppush = nowpush;
        return 2;
    }

    //ボタンを離した瞬間
    else if (tmppush == TRUE && nowpush == FALSE)
    {
        tmppush = nowpush;
        return 3;
    }
    //ボタンが押されていない
    else {
        tmppush = nowpush;
        return 0;
    }
}
