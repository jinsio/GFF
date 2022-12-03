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

    //�{�^���������ꂽ�u��
    if (tmppush == FALSE && nowpush == TRUE)
    {
        ret = 1;
    }

    //�{�^��������������Ă�����
    else if (tmppush == TRUE && nowpush == TRUE)
    {
        ret = 2;
    }

    //�{�^���𗣂����u��
    else if (tmppush == TRUE && nowpush == FALSE)
    {
        ret = 3;
    }
    //�{�^����������Ă��Ȃ�
   
    else {
        ret = 0;
    }
    tmppush = nowpush;
    return ret;
}
