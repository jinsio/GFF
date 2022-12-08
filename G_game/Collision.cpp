#include "Collision.h"
#include "Player.h"
#include <math.h>



//-------------------------------------------------//
// @briaf   コンストラクター
//-------------------------------------------------//
Collision::Collision()
//.....変数初期化.....//
    :Marker(0)
    , rawNum(0)
    , columnNum(0)
    , num(0)
    , eofFlag(false)
    , fp(NULL)
    , isStand(false)
{


    LoadDivGraph("assets/mapArufa/collision_check.png", 2, 2, 1, BOX_WIDTH, BOX_HEIGHT, colBoxHandle);//当たり判定チェック用画像
    fopen_s(&fp, "assets/mapArufa/Maoumap_collisionB1.csv", "r");          //fopen_s関数でcsvファイルを読み取り形式で開く
    if (fp == NULL)                                                            //fpが空の時は
    {
        DebugBreak();                                                         //デバッグ中止
    }
    memset(buffer, 0, sizeof(buffer));                        //memset関数でメモリにbufferをセット、sizeof演算子で要素数を決める

    while (!eofFlag)
    {
        while (!eofFlag)
        {
            Marker = fgetc(fp);                                        //fpから文字を読んでMarkerに格納
            if (Marker == EOF)eofFlag = true;                                 //EOFを検出したらフラグを立てる

            if (Marker != ',' && Marker != '\n')                               //区切り化改行でなければ
            {
                strcat_s(buffer, (const char*)&Marker);    //bufferに連結して、const char関数で書き換える
            }
            else
            {
                num = atoi(buffer);                                    //bufferをint型に直してnumに代入
                sCol[columnNum][rawNum].BoxHandle = colBoxHandle[num];        //num番号のハンドルを取得
                memset(buffer, 0, sizeof(buffer));            //memset関数でメモリにbufferをセット、sizeof演算子で要素数を決める
                break;                                                        //区切りか改行なのでループで抜ける
            }
        }
        if (Marker == ',')
        {
            columnNum++;
        }
        if (Marker == '\n')
        {
            rawNum++; columnNum = 0;                 //区切りは列を増やし、改行は行を増やして列を0にする
        }
    }
    fclose(fp);                                                       //ファイルを閉じる
}

//-------------------------------------------------//
// @briaf   デストラクター
//-------------------------------------------------//
Collision::~Collision()
{
}

//-------------------------------------------------//
// @briaf   当たり判定
//-------------------------------------------------//
bool Collision::ColBox(VECTOR& objPos)
{
    //オブジェクトBOXの頂点座標//
    int objLX = ((int)objPos.x - XSize / 4) - (int)colPos.x;
    int objLY = ((int)objPos.y - YSize / 4) - (int)colPos.y;
    int objRX = ((int)objPos.x + XSize / 4) - (int)colPos.x;
    int objRY = ((int)objPos.y + YSize / 3) - (int)colPos.y;

    //現在のタイル位置//
    int tileLX = objLX / BOX_WIDTH ;
    int tileLY = objLY / BOX_HEIGHT;
    int tileRX = objRX / BOX_WIDTH ;
    int tileRY = objRY / BOX_HEIGHT;

    for (int iy = tileLY; iy < tileRY + 1; iy++)
    {
        for (int jx = tileLX; jx < tileRX + 1; jx++)
        {
            //当たり判定BOXの頂点座標//
            int boxLX = jx * BOX_WIDTH;
            int boxLY = iy * BOX_HEIGHT;
            int boxRX = boxLX + BOX_WIDTH;
            int boxRY = boxLY + BOX_HEIGHT;

            //押し出し処理//
            int bx1 = boxLX - objRX;
            int bx2 = boxRX - objLX;
            int by1 = boxLY - objRY;
            int by2 = boxRY - objLY;

            int bx = (abs(bx1) < abs(bx2)) ? bx1 * 1.5f : bx2 * 1.5f;
            int by = (abs(by1) < abs(by2)) ? by1 : by2;
            if (sCol[jx][iy].BoxHandle == colBoxHandle[1])
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
        }
    }


    return false;


}

