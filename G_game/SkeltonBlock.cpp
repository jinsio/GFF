#include "DxLib.h"
#include "SkeltonBlock.h"


//-------------------------------------------------//
// @briaf   �R���X�g���N�^
//-------------------------------------------------//
SkeltonBlock::SkeltonBlock() :                                  //���ԂȂ���ň���ǂݍ���ł܂��@���Ԃł��ċ����킢����z��ɂ��܂�
    //1�Ԗڂ̃u���b�N
    FirstFalseImg(LoadGraph("assets/block/Block(false).png")),
    FirstTrueImg(LoadGraph("assets/block/Block(true).png")),
    //2�Ԗڂ̃u���b�N
    SecondFalseImg(LoadGraph("assets/block/Block(false).png")),
    SecondTrueImg(LoadGraph("assets/block/Block(true).png")),
    //3�Ԗڂ̃u���b�N
    ThirdFalseImg(LoadGraph("assets/block/Block(false).png")),
    ThirdTrueImg(LoadGraph("assets/block/Block(true).png")),
    //4�Ԗڂ̃u���b�N
    FourthFalseImg(LoadGraph("assets/block/Block(false).png")),
    FourthTrueImg(LoadGraph("assets/block/Block(true).png")),
    //5�Ԗڂ̃u���b�N
    FifthFalseImg(LoadGraph("assets/block/Block(false).png")),
    FifthTrueImg(LoadGraph("assets/block/Block(true).png")),
    //6�Ԗڂ̃u���b�N
    SixthFalseImg(LoadGraph("assets/block/Block(false).png")),
    SixthTrueImg(LoadGraph("assets/block/Block(true).png"))

{
    //1�Ԗڂ̃u���b�N
    FirstX = FIRST_POSITION_X;
    FirstY = FIRST_POSITION_Y;
    FirstVisibleFlag = false;

    //2�Ԗڂ̃u���b�N
    SecondX = SECOND_POSITION_X;
    SecondY = SECOND_POSITION_Y;
    SecondVisibleFlag = false;

    //3�Ԗڂ̃u���b�N
    ThirdX = THIRD_POSITION_X;
    ThirdY = THIRD_POSITION_Y;
    ThirdVisibleFlag = false;

    //4�Ԗڂ̃u���b�N
    FourthX = FOURTH_POSITION_X;
    FourthY = FOURTH_POSITION_Y;
    FourthVisibleFlag = false;

    //5�Ԗڂ̃u���b�N
    FifthX = FIFTH_POSITION_X;
    FifthY = FIFTH_POSITION_Y;
    FifthVisibleFlag = false;

    //6�Ԗڂ̃u���b�N
    SixthX = SIXTH_POSITION_X;
    SixthY = SIXTH_POSITION_Y;
    SixthVisibleFlag = false;

    //�����E��
    W = BLOCK_WIDTH;
    H = BLOCK_HEIGHT;
}

//-------------------------------------------------//
// @briaf   ����`�F�b�N
// @param   First    1�Ԗڂ̃u���b�N
// @param   Second   2�Ԗڂ̃u���b�N
// @param   Third    3�Ԗڂ̃u���b�N
// @param   Fourth   4�Ԗڂ̃u���b�N
// @param   Fifth    5�Ԗڂ̃u���b�N
// @param   Sixth    6�Ԗڂ̃u���b�N
//-------------------------------------------------//
void SkeltonBlock::CheckPlayerHit(Player* player)
{
    //1�Ԗڂ̃u���b�N
    if ((PlayerFirstColBox(player->GetPosition())))
    {
        player->SetonGround(true);
    }
    //2�Ԗڂ̃u���b�N
    if ((PlayerSecondColBox(player->GetPosition())))
    {
        player->SetonGround(true);
    }
    //3�Ԗڂ̃u���b�N
    if ((PlayerThirdColBox(player->GetPosition())))
    {
        player->SetonGround(true);
    }
    //4�Ԗڂ̃u���b�N
    if ((PlayerFourthColBox(player->GetPosition())))
    {
        player->SetonGround(true);
    }
    //5�Ԗڂ̃u���b�N
    if ((PlayerFifthColBox(player->GetPosition())))
    {
        player->SetonGround(true);
    }
    //6�Ԗڂ̃u���b�N
    if ((PlayerSixthColBox(player->GetPosition())))
    {
        player->SetonGround(true);
    }
}

void SkeltonBlock::CheckBulletHit(Bullet* bullet)
{
    //1�Ԗ�
    if (BulletFirstColBox(bullet->GetPosition()))
    {
        bullet->SetonGround(true);
    }
    //2�Ԗ�
    if (BulletSecondColBox(bullet->GetPosition()))
    {
        bullet->SetonGround(true);
    }
    //3�Ԗ�
    if (BulletThirdColBox(bullet->GetPosition()))
    {
        bullet->SetonGround(true);
    }
    //4�Ԗ�
    if (BulletFourthColBox(bullet->GetPosition()))
    {
        bullet->SetonGround(true);
    }
    //5�Ԗ�
    if (BulletFifthColBox(bullet->GetPosition()))
    {
        bullet->SetonGround(true);
    }
    //6�Ԗ�
    if (BulletSixthColBox(bullet->GetPosition()))
    {
        bullet->SetonGround(true);
    }
}

//------------------------------------------------ -//
// @briaf   �����蔻��
// @param   First    1�Ԗڂ̃u���b�N
// @param   Second   2�Ԗڂ̃u���b�N
// @param   Third    3�Ԗڂ̃u���b�N
// @param   Fourth   4�Ԗڂ̃u���b�N
// @param   Fifth    5�Ԗڂ̃u���b�N
// @param   Sixth    6�Ԗڂ̃u���b�N
//-------------------------------------------------//

//1�Ԗ�
bool SkeltonBlock::PlayerFirstColBox(VECTOR& objPos)
{
    //�I�u�W�F�N�gBOX�̒��_���W//
    //�v���C���[
    int objLX = ((int)objPos.x - XSize / 4);
    int objLY = ((int)objPos.y - YSize / 4);
    int objRX = ((int)objPos.x + XSize / 4);
    int objRY = ((int)objPos.y + YSize / 1.5f);

    //�u���b�N�ϐ�//
    int FirstBlockLX = FirstX;
    int FirstBlockLY = FirstY;
    int FirstBlockRX = FirstX + W;
    int FirstBlockRY = FirstY + H;


    //�����o������//
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
    //�I�u�W�F�N�gBOX�̒��_���W//
    //�e
    int objLX = ((int)objPos.x - XSize / 4);
    int objLY = ((int)objPos.y - YSize / 4);
    int objRX = ((int)objPos.x + XSize / 4);
    int objRY = ((int)objPos.y + YSize / 1.5f);

    //�u���b�N�ϐ�//
    int FirstBlockLX = FirstX;
    int FirstBlockLY = FirstY;
    int FirstBlockRX = FirstX + W;
    int FirstBlockRY = FirstY + H;



    //�����o������//
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

//2�Ԗ�
bool SkeltonBlock::PlayerSecondColBox(VECTOR& objPos)
{
    //�I�u�W�F�N�gBOX�̒��_���W//
    //�v���C���[
    int objLX = ((int)objPos.x - XSize / 4);
    int objLY = ((int)objPos.y - YSize / 4);
    int objRX = ((int)objPos.x + XSize / 4);
    int objRY = ((int)objPos.y + YSize / 1.5f);

    int SecondBlockLX = SecondX;
    int SecondBlockLY = SecondY;
    int SecondBlockRX = SecondX + W;
    int SecondBlockRY = SecondY + H;

    //�����o������//
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
    //�I�u�W�F�N�gBOX�̒��_���W//
   //�e
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

//3�Ԗ�
bool SkeltonBlock::PlayerThirdColBox(VECTOR& objPos)
{
    //�I�u�W�F�N�gBOX�̒��_���W//
    //�v���C���[
    int objLX = ((int)objPos.x - XSize / 4);
    int objLY = ((int)objPos.y - YSize / 4);
    int objRX = ((int)objPos.x + XSize / 4);
    int objRY = ((int)objPos.y + YSize / 1.5f);

    int ThirdBlockLX = ThirdX;
    int ThirdBlockLY = ThirdY;
    int ThirdBlockRX = ThirdX + W;
    int ThirdBlockRY = ThirdY + H;

    //�����o������//
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
    //�I�u�W�F�N�gBOX�̒��_���W//
   //�e
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

//4�Ԗ�
bool SkeltonBlock::PlayerFourthColBox(VECTOR& objPos)
{
    //�I�u�W�F�N�gBOX�̒��_���W//
    //�v���C���[
    int objLX = ((int)objPos.x - XSize / 4);
    int objLY = ((int)objPos.y - YSize / 4);
    int objRX = ((int)objPos.x + XSize / 4);
    int objRY = ((int)objPos.y + YSize / 1.5f);

    //�u���b�N�ϐ�//
    int FourthBlockLX = FourthX;
    int FourthBlockLY = FourthY;
    int FourthBlockRX = FourthX + W;
    int FourthBlockRY = FourthY + H;


    //�����o������//
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
    //�I�u�W�F�N�gBOX�̒��_���W//
    //�e
    int objLX = ((int)objPos.x - XSize / 4);
    int objLY = ((int)objPos.y - YSize / 4);
    int objRX = ((int)objPos.x + XSize / 4);
    int objRY = ((int)objPos.y + YSize / 1.5f);

    //�u���b�N�ϐ�//
    int FourthBlockLX = FourthX;
    int FourthBlockLY = FourthY;
    int FourthBlockRX = FourthX + W;
    int FourthBlockRY = FourthY + H;



    //�����o������//
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

//5�Ԗ�
bool SkeltonBlock::PlayerFifthColBox(VECTOR& objPos)
{
    //�I�u�W�F�N�gBOX�̒��_���W//
    //�v���C���[
    int objLX = ((int)objPos.x - XSize / 4);
    int objLY = ((int)objPos.y - YSize / 4);
    int objRX = ((int)objPos.x + XSize / 4);
    int objRY = ((int)objPos.y + YSize / 1.5f);

    //�u���b�N�ϐ�//
    int FifthBlockLX = FifthX;
    int FifthBlockLY = FifthY;
    int FifthBlockRX = FifthX + W;
    int FifthBlockRY = FifthY + H;


    //�����o������//
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
    //�I�u�W�F�N�gBOX�̒��_���W//
    //�e
    int objLX = ((int)objPos.x - XSize / 4);
    int objLY = ((int)objPos.y - YSize / 4);
    int objRX = ((int)objPos.x + XSize / 4);
    int objRY = ((int)objPos.y + YSize / 1.5f);

    //�u���b�N�ϐ�//
    int FifthBlockLX = FifthX;
    int FifthBlockLY = FifthY;
    int FifthBlockRX = FifthX + W;
    int FifthBlockRY = FifthY + H;



    //�����o������//
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

//6�Ԗ�
bool SkeltonBlock::PlayerSixthColBox(VECTOR& objPos)
{
    //�I�u�W�F�N�gBOX�̒��_���W//
    //�v���C���[
    int objLX = ((int)objPos.x - XSize / 4);
    int objLY = ((int)objPos.y - YSize / 4);
    int objRX = ((int)objPos.x + XSize / 4);
    int objRY = ((int)objPos.y + YSize / 1.5f);

    //�u���b�N�ϐ�//
    int SixthBlockLX = SixthX;
    int SixthBlockLY = SixthY;
    int SixthBlockRX = SixthX + W;
    int SixthBlockRY = SixthY + H;


    //�����o������//
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
    //�I�u�W�F�N�gBOX�̒��_���W//
    //�e
    int objLX = ((int)objPos.x - XSize / 4);
    int objLY = ((int)objPos.y - YSize / 4);
    int objRX = ((int)objPos.x + XSize / 4);
    int objRY = ((int)objPos.y + YSize / 1.5f);

    //�u���b�N�ϐ�//
    int SixthBlockLX = SixthX;
    int SixthBlockLY = SixthY;
    int SixthBlockRX = SixthX + W;
    int SixthBlockRY = SixthY + H;



    //�����o������//
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
// @briaf   �`��
//-------------------------------------------------//
void SkeltonBlock::Draw(int scrX, int scrY)
{
    //�`��
    //1�Ԗڂ̃u���b�N
    if (FirstVisibleFlag)
    {
        DrawGraph(FirstX - scrX, FirstY - scrY, FirstTrueImg, true);
    }
    else
    {
        DrawGraph(FirstX - scrX, FirstY - scrY, FirstFalseImg, true);
    }
    //2�Ԗڂ̃u���b�N
    if (SecondVisibleFlag)
    {
        DrawGraph(SecondX - scrX, SecondY - scrY, SecondTrueImg, true);
    }
    else
    {
        DrawGraph(SecondX - scrX, SecondY - scrY, SecondFalseImg, true);
    }
    //3�Ԗڂ̃u���b�N
    if (ThirdVisibleFlag)
    {
        DrawGraph(ThirdX - scrX, ThirdY - scrY, ThirdTrueImg, true);
    }
    else
    {
        DrawGraph(ThirdX - scrX, ThirdY - scrY, ThirdFalseImg, true);
    }
    //4�Ԗڂ̃u���b�N
    if (FourthVisibleFlag)
    {
        DrawGraph(FourthX - scrX, FourthY - scrY, FourthTrueImg, true);
    }
    else
    {
        DrawGraph(FourthX - scrX, FourthY - scrY, FourthFalseImg, true);
    }
    //5�Ԗڂ̃u���b�N
    if (FifthVisibleFlag)
    {
        DrawGraph(FifthX - scrX, FifthY - scrY, FifthTrueImg, true);
    }
    else
    {
        DrawGraph(FifthX - scrX, FifthY - scrY, FifthFalseImg, true);
    }
    //6�Ԗڂ̃u���b�N
    if (SixthVisibleFlag)
    {
        DrawGraph(SixthX - scrX, SixthY - scrY, SixthTrueImg, true);
    }
    else
    {
        DrawGraph(SixthX - scrX, SixthY - scrY, SixthFalseImg, true);
    }
}
