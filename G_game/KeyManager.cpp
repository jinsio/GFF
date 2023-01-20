#include "KeyManager.h"

    KeyManager* KeyManager::mpInstance = nullptr;

    bool KeyManager::nowpushI = FALSE;
    bool KeyManager::tmppushI = FALSE;
    bool KeyManager::nowpushP = FALSE;
    bool KeyManager::tmppushP = FALSE;


    KeyManager::KeyManager()
    {
        mpInstance = nullptr;
    }

    KeyManager::~KeyManager()
    {
    }

    void KeyManager::Initialize()
    {
        if (!mpInstance)
        {
        mpInstance = new KeyManager;
        }
    }

    void KeyManager::GetPush_KeyP()
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

    int KeyManager::KeyStatusP()
    {
        GetPush_KeyP();

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

    void KeyManager::GetPush_KeyI()
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

    int KeyManager::KeyStatusI()
    {
        GetPush_KeyI();

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
