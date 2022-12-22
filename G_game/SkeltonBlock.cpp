#include "DxLib.h"
#include "SkeltonBlock.h"


//-------------------------------------------------//
// @briaf   コンストラクタ
//-------------------------------------------------//
SkeltonBlock::SkeltonBlock() :                                  //時間ないんで一つずつ読み込んでます　時間できて興味わいたら配列にします
    //1番目のブロック
    FirstFalseImg(LoadGraph("assets/block/Block(false).png")),
    FirstTrueImg(LoadGraph("assets/block/Block(true).png")),
    //2番目のブロック
    SecondFalseImg(LoadGraph("assets/block/Block(false).png")),
    SecondTrueImg(LoadGraph("assets/block/Block(true).png")),
    //3番目のブロック
    ThirdFalseImg(LoadGraph("assets/block/Block(false).png")),
    ThirdTrueImg(LoadGraph("assets/block/Block(true).png")),
    //4番目のブロック
    FourthFalseImg(LoadGraph("assets/block/Block(false).png")),
    FourthTrueImg(LoadGraph("assets/block/Block(true).png")),
    //5番目のブロック
    FifthFalseImg(LoadGraph("assets/block/Block(false).png")),
    FifthTrueImg(LoadGraph("assets/block/Block(true).png")),
    //6番目のブロック
    SixthFalseImg(LoadGraph("assets/block/Block(false).png")),
    SixthTrueImg(LoadGraph("assets/block/Block(true).png"))

{
    //1番目のブロック
    FirstX = FIRST_POSITION_X;
    FirstY = FIRST_POSITION_Y;
    FirstVisibleFlag = false;

    //2番目のブロック
    SecondX = SECOND_POSITION_X;
    SecondY = SECOND_POSITION_Y;
    SecondVisibleFlag = false;

    //3番目のブロック
    ThirdX = THIRD_POSITION_X;
    ThirdY = THIRD_POSITION_Y;
    ThirdVisibleFlag = false;

    //4番目のブロック
    FourthX = FOURTH_POSITION_X;
    FourthY = FOURTH_POSITION_Y;
    FourthVisibleFlag = false;

    //5番目のブロック
    FifthX = FIFTH_POSITION_X;
    FifthY = FIFTH_POSITION_Y;
    FifthVisibleFlag = false;

    //6番目のブロック
    SixthX = SIXTH_POSITION_X;
    SixthY = SIXTH_POSITION_Y;
    SixthVisibleFlag = false;

    //高さ・幅
    W = BLOCK_WIDTH;
    H = BLOCK_HEIGHT;
}

//-------------------------------------------------//
// @briaf   判定チェック
// @param   First    1番目のブロック
// @param   Second   2番目のブロック
// @param   Third    3番目のブロック
// @param   Fourth   4番目のブロック
// @param   Fifth    5番目のブロック
// @param   Sixth    6番目のブロック
//-------------------------------------------------//
void SkeltonBlock::CheckPlayerHit(Player* player)
{
    //1番目のブロック
    if ((PlayerFirstColBox(player->GetPosition())))
    {
        player->SetonGround(true);
    }
    //2番目のブロック
    if ((PlayerSecondColBox(player->GetPosition())))
    {
        player->SetonGround(true);
    }
    //3番目のブロック
    if ((PlayerThirdColBox(player->GetPosition())))
    {
        player->SetonGround(true);
    }
    //4番目のブロック
    if ((PlayerFourthColBox(player->GetPosition())))
    {
        player->SetonGround(true);
    }
    //5番目のブロック
    if ((PlayerFifthColBox(player->GetPosition())))
    {
        player->SetonGround(true);
    }
    //6番目のブロック
    if ((PlayerSixthColBox(player->GetPosition())))
    {
        player->SetonGround(true);
    }
}

void SkeltonBlock::CheckBulletHit(Bullet* bullet)
{
    //1番目
    if (BulletFirstColBox(bullet->GetPosition()))
    {
        bullet->SetonGround(true);
    }
    //2番目
    if (BulletSecondColBox(bullet->GetPosition()))
    {
        bullet->SetonGround(true);
    }
    //3番目
    if (BulletThirdColBox(bullet->GetPosition()))
    {
        bullet->SetonGround(true);
    }
    //4番目
    if (BulletFourthColBox(bullet->GetPosition()))
    {
        bullet->SetonGround(true);
    }
    //5番目
    if (BulletFifthColBox(bullet->GetPosition()))
    {
        bullet->SetonGround(true);
    }
    //6番目
    if (BulletSixthColBox(bullet->GetPosition()))
    {
        bullet->SetonGround(true);
    }
}

//------------------------------------------------ -//
// @briaf   当たり判定
// @param   First    1番目のブロック
// @param   Second   2番目のブロック
// @param   Third    3番目のブロック
// @param   Fourth   4番目のブロック
// @param   Fifth    5番目のブロック
// @param   Sixth    6番目のブロック
//-------------------------------------------------//

//1番目
bool SkeltonBlock::PlayerFirstColBox(VECTOR& objPos)
{
    //オブジェクトBOXの頂点座標//
    //プレイヤー
    int objLX = ((int)objPos.x - XSize / 4);
    int objLY = ((int)objPos.y - YSize / 4);
    int objRX = ((int)objPos.x + XSize / 4);
    int objRY = ((int)objPos.y + YSize / 1.5f);

    //ブロック変数//
    int FirstBlockLX = FirstX;
    int FirstBlockLY = FirstY;
    int FirstBlockRX = FirstX + W;
    int FirstBlockRY = FirstY + H;


    //押し出し処理//
    int bx1 = FirstBlockLX - objRX;
    int bx2 = FirstBlockRX - objLX;
    int by1 = FirstBlockLY - objRY;
    int by2 = FirstBlockRY - objLY;

    int bx = (abs(bx1) < abs(bx2)) ? bx1 : bx2;
    int by = (abs(by1) < abs(by2)) ? by1 : by2;

    if (FirstVisibleFlag)
    {

        if (objLX <= FirstBlockRX && FirstBlockLX <= objRX &&
            objLY <= FirstBlockRY && FirstBlockLY <= objRY)
        {
            if (abs(bx) < abs(by))
            {

                objPos.x += bx;

            }
            else
            {

                objPos.y += by;
                if (by <= 0)
                {
                    return true;
                }
            }

        }
        return false;
    }


}

bool SkeltonBlock::BulletFirstColBox(VECTOR& objPos)
{
    //オブジェクトBOXの頂点座標//
    //弾
    int objLX = ((int)objPos.x - XSize / 4);
    int objLY = ((int)objPos.y - YSize / 4);
    int objRX = ((int)objPos.x + XSize / 4);
    int objRY = ((int)objPos.y + YSize / 1.5f);

    //ブロック変数//
    int FirstBlockLX = FirstX;
    int FirstBlockLY = FirstY;
    int FirstBlockRX = FirstX + W;
    int FirstBlockRY = FirstY + H;



    //押し出し処理//
    int bx1 = FirstBlockLX - objRX;
    int bx2 = FirstBlockRX - objLX;
    int by1 = FirstBlockLY - objRY;
    int by2 = FirstBlockRY - objLY;

    int bx = (abs(bx1) < abs(bx2)) ? bx1 : bx2;
    int by = (abs(by1) < abs(by2)) ? by1 : by2;

    if (objLX <= FirstBlockRX && FirstBlockLX <= objRX &&
        objLY <= FirstBlockRY && FirstBlockLY <= objRY)
    {
        FirstVisibleFlag = true;
        if (abs(bx) < abs(by))
        {

            objPos.x += bx;

        }
        else
        {

            objPos.y += by;
            if (by <= 0)
            {
                return true;
            }
        }

    }
    return false;
}

//2番目
bool SkeltonBlock::PlayerSecondColBox(VECTOR& objPos)
{
    //オブジェクトBOXの頂点座標//
    //プレイヤー
    int objLX = ((int)objPos.x - XSize / 4);
    int objLY = ((int)objPos.y - YSize / 4);
    int objRX = ((int)objPos.x + XSize / 4);
    int objRY = ((int)objPos.y + YSize / 1.5f);

    int SecondBlockLX = SecondX;
    int SecondBlockLY = SecondY;
    int SecondBlockRX = SecondX + W;
    int SecondBlockRY = SecondY + H;

    //押し出し処理//
    int bx1 = SecondBlockLX - objRX;
    int bx2 = SecondBlockRX - objLX;
    int by1 = SecondBlockLY - objRY;
    int by2 = SecondBlockRY - objLY;

    int bx = (abs(bx1) < abs(bx2)) ? bx1 : bx2;
    int by = (abs(by1) < abs(by2)) ? by1 : by2;

    if (SecondVisibleFlag)
    {
        if (objLX <= SecondBlockRX && SecondBlockLX <= objRX &&
            objLY <= SecondBlockRY && SecondBlockLY <= objRY)
        {
            if (abs(bx) < abs(by))
            {

                objPos.x += bx;

            }
            else
            {

                objPos.y += by;
                if (by <= 0)
                {
                    return true;
                }
            }

        }
        return false;
    }



}

bool SkeltonBlock::BulletSecondColBox(VECTOR& objPos)
{
    //オブジェクトBOXの頂点座標//
   //弾
    int objLX = ((int)objPos.x - XSize / 4);
    int objLY = ((int)objPos.y - YSize / 4);
    int objRX = ((int)objPos.x + XSize / 4);
    int objRY = ((int)objPos.y + YSize / 1.5f);

    int SecondBlockLX = SecondX;
    int SecondBlockLY = SecondY;
    int SecondBlockRX = SecondX + W;
    int SecondBlockRY = SecondY + H;

    int bx1 = SecondBlockLX - objRX;
    int bx2 = SecondBlockRX - objLX;
    int by1 = SecondBlockLY - objRY;
    int by2 = SecondBlockRY - objLY;

    int bx = (abs(bx1) < abs(bx2)) ? bx1 : bx2;
    int by = (abs(by1) < abs(by2)) ? by1 : by2;

    if (objLX <= SecondBlockRX && SecondBlockLX <= objRX &&
        objLY <= SecondBlockRY && SecondBlockLY <= objRY)
    {
        SecondVisibleFlag = true;
        if (abs(bx) < abs(by))
        {

            objPos.x += bx;

        }
        else
        {

            objPos.y += by;
            if (by <= 0)
            {
                return true;
            }
        }

    }
    return false;

}

//3番目
bool SkeltonBlock::PlayerThirdColBox(VECTOR& objPos)
{
    //オブジェクトBOXの頂点座標//
    //プレイヤー
    int objLX = ((int)objPos.x - XSize / 4);
    int objLY = ((int)objPos.y - YSize / 4);
    int objRX = ((int)objPos.x + XSize / 4);
    int objRY = ((int)objPos.y + YSize / 1.5f);

    int ThirdBlockLX = ThirdX;
    int ThirdBlockLY = ThirdY;
    int ThirdBlockRX = ThirdX + W;
    int ThirdBlockRY = ThirdY + H;

    //押し出し処理//
    int bx1 = ThirdBlockLX - objRX;
    int bx2 = ThirdBlockRX - objLX;
    int by1 = ThirdBlockLY - objRY;
    int by2 = ThirdBlockRY - objLY;

    int bx = (abs(bx1) < abs(bx2)) ? bx1 : bx2;
    int by = (abs(by1) < abs(by2)) ? by1 : by2;

    if (ThirdVisibleFlag)
    {
        if (objLX <= ThirdBlockRX && ThirdBlockLX <= objRX &&
            objLY <= ThirdBlockRY && ThirdBlockLY <= objRY)
        {
            if (abs(bx) < abs(by))
            {

                objPos.x += bx;

            }
            else
            {

                objPos.y += by;
                if (by <= 0)
                {
                    return true;
                }
            }

        }
        return false;
    }
}

bool SkeltonBlock::BulletThirdColBox(VECTOR& objPos)
{
    //オブジェクトBOXの頂点座標//
   //弾
    int objLX = ((int)objPos.x - XSize / 4);
    int objLY = ((int)objPos.y - YSize / 4);
    int objRX = ((int)objPos.x + XSize / 4);
    int objRY = ((int)objPos.y + YSize / 1.5f);

    int ThirdBlockLX = ThirdX;
    int ThirdBlockLY = ThirdY;
    int ThirdBlockRX = ThirdX + W;
    int ThirdBlockRY = ThirdY + H;

    int bx1 = ThirdBlockLX - objRX;
    int bx2 = ThirdBlockRX - objLX;
    int by1 = ThirdBlockLY - objRY;
    int by2 = ThirdBlockRY - objLY;

    int bx = (abs(bx1) < abs(bx2)) ? bx1 : bx2;
    int by = (abs(by1) < abs(by2)) ? by1 : by2;

    if (objLX <= ThirdBlockRX && ThirdBlockLX <= objRX &&
        objLY <= ThirdBlockRY && ThirdBlockLY <= objRY)
    {
        ThirdVisibleFlag = true;
        if (abs(bx) < abs(by))
        {

            objPos.x += bx;

        }
        else
        {

            objPos.y += by;
            if (by <= 0)
            {
                return true;
            }
        }

    }
    return false;

}

//4番目
bool SkeltonBlock::PlayerFourthColBox(VECTOR& objPos)
{
    //オブジェクトBOXの頂点座標//
    //プレイヤー
    int objLX = ((int)objPos.x - XSize / 4);
    int objLY = ((int)objPos.y - YSize / 4);
    int objRX = ((int)objPos.x + XSize / 4);
    int objRY = ((int)objPos.y + YSize / 1.5f);

    //ブロック変数//
    int FourthBlockLX = FourthX;
    int FourthBlockLY = FourthY;
    int FourthBlockRX = FourthX + W;
    int FourthBlockRY = FourthY + H;


    //押し出し処理//
    int bx1 = FourthBlockLX - objRX;
    int bx2 = FourthBlockRX - objLX;
    int by1 = FourthBlockLY - objRY;
    int by2 = FourthBlockRY - objLY;

    int bx = (abs(bx1) < abs(bx2)) ? bx1 : bx2;
    int by = (abs(by1) < abs(by2)) ? by1 : by2;

    if (FourthVisibleFlag)
    {

        if (objLX <= FourthBlockRX && FourthBlockLX <= objRX &&
            objLY <= FourthBlockRY && FourthBlockLY <= objRY)
        {
            if (abs(bx) < abs(by))
            {

                objPos.x += bx;

            }
            else
            {

                objPos.y += by;
                if (by <= 0)
                {
                    return true;
                }
            }

        }
        return false;
    }


}

bool SkeltonBlock::BulletFourthColBox(VECTOR& objPos)
{
    //オブジェクトBOXの頂点座標//
    //弾
    int objLX = ((int)objPos.x - XSize / 4);
    int objLY = ((int)objPos.y - YSize / 4);
    int objRX = ((int)objPos.x + XSize / 4);
    int objRY = ((int)objPos.y + YSize / 1.5f);

    //ブロック変数//
    int FourthBlockLX = FourthX;
    int FourthBlockLY = FourthY;
    int FourthBlockRX = FourthX + W;
    int FourthBlockRY = FourthY + H;



    //押し出し処理//
    int bx1 = FourthBlockLX - objRX;
    int bx2 = FourthBlockRX - objLX;
    int by1 = FourthBlockLY - objRY;
    int by2 = FourthBlockRY - objLY;

    int bx = (abs(bx1) < abs(bx2)) ? bx1 : bx2;
    int by = (abs(by1) < abs(by2)) ? by1 : by2;

    if (objLX <= FourthBlockRX && FourthBlockLX <= objRX &&
        objLY <= FourthBlockRY && FourthBlockLY <= objRY)
    {
        FourthVisibleFlag = true;
        if (abs(bx) < abs(by))
        {

            objPos.x += bx;

        }
        else
        {

            objPos.y += by;
            if (by <= 0)
            {
                return true;
            }
        }

    }
    return false;

}

//5番目
bool SkeltonBlock::PlayerFifthColBox(VECTOR& objPos)
{
    //オブジェクトBOXの頂点座標//
    //プレイヤー
    int objLX = ((int)objPos.x - XSize / 4);
    int objLY = ((int)objPos.y - YSize / 4);
    int objRX = ((int)objPos.x + XSize / 4);
    int objRY = ((int)objPos.y + YSize / 1.5f);

    //ブロック変数//
    int FifthBlockLX = FifthX;
    int FifthBlockLY = FifthY;
    int FifthBlockRX = FifthX + W;
    int FifthBlockRY = FifthY + H;


    //押し出し処理//
    int bx1 = FifthBlockLX - objRX;
    int bx2 = FifthBlockRX - objLX;
    int by1 = FifthBlockLY - objRY;
    int by2 = FifthBlockRY - objLY;

    int bx = (abs(bx1) < abs(bx2)) ? bx1 : bx2;
    int by = (abs(by1) < abs(by2)) ? by1 : by2;

    if (FifthVisibleFlag)
    {

        if (objLX <= FifthBlockRX && FifthBlockLX <= objRX &&
            objLY <= FifthBlockRY && FifthBlockLY <= objRY)
        {
            if (abs(bx) < abs(by))
            {

                objPos.x += bx;

            }
            else
            {

                objPos.y += by;
                if (by <= 0)
                {
                    return true;
                }
            }

        }
        return false;
    }


}

bool SkeltonBlock::BulletFifthColBox(VECTOR& objPos)
{
    //オブジェクトBOXの頂点座標//
    //弾
    int objLX = ((int)objPos.x - XSize / 4);
    int objLY = ((int)objPos.y - YSize / 4);
    int objRX = ((int)objPos.x + XSize / 4);
    int objRY = ((int)objPos.y + YSize / 1.5f);

    //ブロック変数//
    int FifthBlockLX = FifthX;
    int FifthBlockLY = FifthY;
    int FifthBlockRX = FifthX + W;
    int FifthBlockRY = FifthY + H;



    //押し出し処理//
    int bx1 = FifthBlockLX - objRX;
    int bx2 = FifthBlockRX - objLX;
    int by1 = FifthBlockLY - objRY;
    int by2 = FifthBlockRY - objLY;

    int bx = (abs(bx1) < abs(bx2)) ? bx1 : bx2;
    int by = (abs(by1) < abs(by2)) ? by1 : by2;

    if (objLX <= FifthBlockRX && FifthBlockLX <= objRX &&
        objLY <= FifthBlockRY && FifthBlockLY <= objRY)
    {
        FifthVisibleFlag = true;
        if (abs(bx) < abs(by))
        {

            objPos.x += bx;

        }
        else
        {

            objPos.y += by;
            if (by <= 0)
            {
                return true;
            }
        }

    }
    return false;
}

//6番目
bool SkeltonBlock::PlayerSixthColBox(VECTOR& objPos)
{
    //オブジェクトBOXの頂点座標//
    //プレイヤー
    int objLX = ((int)objPos.x - XSize / 4);
    int objLY = ((int)objPos.y - YSize / 4);
    int objRX = ((int)objPos.x + XSize / 4);
    int objRY = ((int)objPos.y + YSize / 1.5f);

    //ブロック変数//
    int SixthBlockLX = SixthX;
    int SixthBlockLY = SixthY;
    int SixthBlockRX = SixthX + W;
    int SixthBlockRY = SixthY + H;


    //押し出し処理//
    int bx1 = SixthBlockLX - objRX;
    int bx2 = SixthBlockRX - objLX;
    int by1 = SixthBlockLY - objRY;
    int by2 = SixthBlockRY - objLY;

    int bx = (abs(bx1) < abs(bx2)) ? bx1 : bx2;
    int by = (abs(by1) < abs(by2)) ? by1 : by2;

    if (SixthVisibleFlag)
    {

        if (objLX <= SixthBlockRX && SixthBlockLX <= objRX &&
            objLY <= SixthBlockRY && SixthBlockLY <= objRY)
        {
            if (abs(bx) < abs(by))
            {

                objPos.x += bx;

            }
            else
            {

                objPos.y += by;
                if (by <= 0)
                {
                    return true;
                }
            }

        }
        return false;
    }


}

bool SkeltonBlock::BulletSixthColBox(VECTOR& objPos)
{
    //オブジェクトBOXの頂点座標//
    //弾
    int objLX = ((int)objPos.x - XSize / 4);
    int objLY = ((int)objPos.y - YSize / 4);
    int objRX = ((int)objPos.x + XSize / 4);
    int objRY = ((int)objPos.y + YSize / 1.5f);

    //ブロック変数//
    int SixthBlockLX = SixthX;
    int SixthBlockLY = SixthY;
    int SixthBlockRX = SixthX + W;
    int SixthBlockRY = SixthY + H;



    //押し出し処理//
    int bx1 = SixthBlockLX - objRX;
    int bx2 = SixthBlockRX - objLX;
    int by1 = SixthBlockLY - objRY;
    int by2 = SixthBlockRY - objLY;

    int bx = (abs(bx1) < abs(bx2)) ? bx1 : bx2;
    int by = (abs(by1) < abs(by2)) ? by1 : by2;

    if (objLX <= SixthBlockRX && SixthBlockLX <= objRX &&
        objLY <= SixthBlockRY && SixthBlockLY <= objRY)
    {
        SixthVisibleFlag = true;
        if (abs(bx) < abs(by))
        {

            objPos.x += bx;

        }
        else
        {

            objPos.y += by;
            if (by <= 0)
            {
                return true;
            }
        }

    }
    return false;
}


//------------------------------------------------ -//
// @briaf   描画
//-------------------------------------------------//
void SkeltonBlock::Draw(int scrX, int scrY)
{
    //描画
    //1番目のブロック
    if (FirstVisibleFlag)
    {
        DrawGraph(FirstX - scrX, FirstY - scrY, FirstTrueImg, true);
    }
    else
    {
        DrawGraph(FirstX - scrX, FirstY - scrY, FirstFalseImg, true);
    }
    //2番目のブロック
    if (SecondVisibleFlag)
    {
        DrawGraph(SecondX - scrX, SecondY - scrY, SecondTrueImg, true);
    }
    else
    {
        DrawGraph(SecondX - scrX, SecondY - scrY, SecondFalseImg, true);
    }
    //3番目のブロック
    if (ThirdVisibleFlag)
    {
        DrawGraph(ThirdX - scrX, ThirdY - scrY, ThirdTrueImg, true);
    }
    else
    {
        DrawGraph(ThirdX - scrX, ThirdY - scrY, ThirdFalseImg, true);
    }
    //4番目のブロック
    if (FourthVisibleFlag)
    {
        DrawGraph(FourthX - scrX, FourthY - scrY, FourthTrueImg, true);
    }
    else
    {
        DrawGraph(FourthX - scrX, FourthY - scrY, FourthFalseImg, true);
    }
    //5番目のブロック
    if (FifthVisibleFlag)
    {
        DrawGraph(FifthX - scrX, FifthY - scrY, FifthTrueImg, true);
    }
    else
    {
        DrawGraph(FifthX - scrX, FifthY - scrY, FifthFalseImg, true);
    }
    //6番目のブロック
    if (SixthVisibleFlag)
    {
        DrawGraph(SixthX - scrX, SixthY - scrY, SixthTrueImg, true);
    }
    else
    {
        DrawGraph(SixthX - scrX, SixthY - scrY, SixthFalseImg, true);
    }
}
