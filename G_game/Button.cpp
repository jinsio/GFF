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
 

    //�{�^���������ꂽ�u��
    if (tmppush == FALSE && nowpush == TRUE)
    {
        tmppush = nowpush;
        return 1;
    }

    //�{�^��������������Ă�����
    else if (tmppush == TRUE && nowpush == TRUE)
    {
        tmppush = nowpush;
        return 2;
    }

    //�{�^���𗣂����u��
    else if (tmppush == TRUE && nowpush == FALSE)
    {
        tmppush = nowpush;
        return 3;
    }
    //�{�^����������Ă��Ȃ�
    else {
        tmppush = nowpush;
        return 0;
    }
}
