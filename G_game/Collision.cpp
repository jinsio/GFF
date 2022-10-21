#include "Collision.h"
#include"Player.h"

Player* player = new Player();

//-------------------------------------------------//
// @briaf   コンストラクター
//-------------------------------------------------//
Collision::Collision()
//.....変数初期化.....//
    :Marker(0)
    ,rawNum(0)
    ,columnNum(0)
    ,num(0)
    ,eofFlag(false)

{
    fopen_s(&fp, "MaouMapCollision.csv", "r");          //fopen_s関数でcsvファイルを読み取り形式で開く
    if (fp = NULL)                                                            //fpが空の時は
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
void Collision::ColBox()
{
    
}