#include "Collision.h"
#include"Player.h"
#include <math.h>

Player* player = new Player();

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
{
    fopen_s(&fp, "assets/map/MaouMapCollision.csv", "r");          //fopen_s関数でcsvファイルを読み取り形式で開く
    if (fp == NULL)                                                            //fpが空の時は
    {
        DebugBreak();                                                         //デバッグ中止
    }
    memset(buffer, 0, sizeof(buffer));                        //memset関数でメモリにbufferをセット、sizeof演算子で要素数を決める

    while (eofFlag)
    {
        while (eofFlag)
        {
            Marker = fgetc(fp);                                        //fpから文字を読んでMarkerに格納
            if (Marker == EOF)eofFlag = true;                                 //EOFを検出したらフラグを立てる

            if (Marker != ','&& Marker != '\n')                               //区切り化改行でなければ
            {
                strcat_s(buffer, (const char*)Marker);    //bufferに連結して、const char関数で書き換える
            }
            else
            {
                num = atoi(buffer);                                    //bufferをint型に直してnumに代入
                sCol[columnNum][rawNum].BoxHandle = colBoxHandle[num];        //num番号のハンドルを取得
                memset(buffer, 0, sizeof(buffer));            //memset関数でメモリにbufferをセット、sizeof演算子で要素数を決める
                break;                                                        //区切りか改行なのでループで抜ける
            }
        }
        Marker = ',' ? columnNum++ : rawNum++, columnNum = 0;                 //区切りは列を増やし、改行は行を増やして列を0にする
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
    int objLX = (objPos.x - XSize)/BOX_WIDTH;
    int objLY = (objPos.y - YSize) / BOX_HEIGHT;
    int objRX = (objPos.x + XSize) / BOX_WIDTH;
    int objRY = (objPos.y + YSize) / BOX_HEIGHT;


    for (int iy = objLY ; iy < objRY; iy++)
    {
        for (int jx = objLX; jx < objRX; jx++)
        {
            //当たり判定BOXの頂点座標//
            colBox.left.x = jx * BOX_WIDTH;
            colBox.left.y = iy * BOX_HEIGHT;
            colBox.right.x = colBox.left.x + BOX_WIDTH;
            colBox.right.y = colBox.left.y + BOX_HEIGHT;

            //衝突した際の押し戻し処理//
            int pbX1 = colBox.left.x - (objPos.x - XSize);
            int pbX2 = colBox.right.x -(objPos.y - YSize);
            int pbY1 = colBox.left.y - (objPos.x + XSize);
            int pbY2 = colBox.right.y -(objPos.y + YSize);

            pb.x = (abs(pbX1) < abs(pbX2)) ? pbX1 : pbX2;
            pb.y = (abs(pbY1) < abs(pbY2)) ? pbY1 : pbY2;

            if (sCol[jx][iy].BoxHandle = colBoxHandle[1])                //ブロックに当たったら
            {
                abs((int)pb.x) < abs((int)pb.y) ? objPos.x += pb.x : objPos.y += pb.y;  //押し戻す
                return true;                                            //ブロックに当たっているという意味のtrueを返す
            }
            else                                                         //ブロックに当たっていなかったら
            {
                return false;                                           //ブロックに当たっていないという意味のfalseを返す
            }
        }
    }
}