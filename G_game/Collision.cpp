#include "Collision.h"
#include "Math/Math.h"



//-------------------------------------------------//
// @briaf   コンストラクター
//-------------------------------------------------//
Collision::Collision()
    :Marker(0)
    , rawNum(0)
    , columnNum(0)
    , num(0)
    , eofFlag(false)
    , fp(NULL)
{


    LoadDivGraph("assets/mapArufa/collision_new_check.png", 5, 5, 1, BOX_WIDTH, BOX_HEIGHT, colBoxHandle);//当たり判定チェック用画像
    fopen_s(&fp, "assets/mapArufa/Maoumap_collision.csv", "r");          //fopen_s関数でcsvファイルを読み取り形式で開く
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

Block::Block(const VECTOR& pos)
    :mSize{ BOX_WIDTH,BOX_HEIGHT,0 }
    , localPos(pos)
    , worldPos(pos)
{
}

void Block::Move(VECTOR& pos)
{
    worldPos = localPos + pos;
}

Model::Model(const VECTOR& size, const VECTOR& pos)
    :mSize(size)
    , localPos(pos)
    , worldPos(pos)
{
}

void Model::Move(VECTOR& pos)
{
    worldPos = localPos + pos;
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
bool Collision::ColBox(const Model& model, const Block& block)
{
    //オブジェクトBOXの頂点座標//
    int objLX = (model.worldPos.x - model.mSize.x / 4);
    int objLY = (model.worldPos.y - model.mSize.y / 4);
    int objRX = (model.worldPos.x + model.mSize.x / 4);
    int objRY = (model.worldPos.y + model.mSize.y / 1.5f);

    //現在のタイル位置//
    int tileLX = objLX / block.mSize.x;
    int tileLY = objLY / block.mSize.y;
    int tileRX = objRX / block.mSize.x;
    int tileRY = objRY / block.mSize.y;

    for (int iy = tileLY; iy < tileRY + 1; iy++)
    {
        for (int jx = tileLX; jx < tileRX + 1; jx++)
        {
            //当たり判定BOXの頂点座標//
            int boxLX = jx * block.mSize.x;
            int boxLY = iy * block.mSize.y;
            int boxRX = boxLX + block.mSize.x;
            int boxRY = boxLY + block.mSize.y;

            //押し出し処理//
            int bx1 = boxLX - objRX;
            int bx2 = boxRX - objLX;
            int by1 = boxLY - objRY;
            int by2 = boxRY - objLY;
            bx = (abs(bx1) < abs(bx2)) ? bx1 : bx2;
            by = (abs(by1) < abs(by2)) ? by1 : by2;

        }
    }
    return isGround;
}

bool Collision::ColHitPair(const Block& block, int i, int j, int colType)
{
    if (sCol[j][i].BoxHandle != block.boxHandle[colType])
    {
        return true;
    }
    return false;
}

bool Collision::ColHitPair(const Model& model, const Model& model2)
{
    if (model.worldPos.x<model2.worldPos.x + model2.mSize.x &&
        model.worldPos.x + model.mSize.x>model2.worldPos.x)
    {
        if (model.worldPos.y<model2.worldPos.y+model2.mSize.y&&
            model.worldPos.y+model.mSize.y>model2.worldPos.y)
        {
            return true;
        }
    }
    return false;
}


VECTOR Collision::CalcPushBack(int i,int j,int colType)
{
    if (abs(bx) < abs(by))
    {
        if (sCol[j - 1][i].BoxHandle == colBoxHandle[colType] ||
            sCol[j + 1][i].BoxHandle == colBoxHandle[colType])
        {
            pushBack.x = bx;
        }
    }
    else
    {
        if (sCol[j][i - 1].BoxHandle == colBoxHandle[colType] ||
            sCol[j][i + 1].BoxHandle == colBoxHandle[colType])
        {
            pushBack.y += by;
            if (by <= 0)
            {
                isGround= true;
            }
        }
    }
    isGround = false;
    return pushBack;
}