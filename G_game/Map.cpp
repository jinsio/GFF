#include "Map.h"

Map::Map()
{
	LoadDivGraph("assets/mapArufa/mapsozai.png",  (200 / 40)* (40 / 32), 200 / 40,  40, 40, 40, chipgraphicHandle);
	FILE* filePointer;
	fopen_s(&filePointer, "assets/mapArufa/Maoumap_map.csv", "r");																//fopen_s関数でmap.csvを読み取り形式で開く
	if (filePointer == NULL)																			//filePointerが空の場合は
	{
		DebugBreak();																					//デバッグ中止
	}
	memset(buffer, 0, sizeof(buffer));																	//memset関数でメモリにbufferをセットし、sizeof演算子で要素数を決める

	while (1)
	{
		while (1)
		{
			characterPack = fgetc(filePointer);										//fgetc関数でfilepointerから文字を読んでcharacterPackに格納
			if (characterPack == EOF)
			{
				eofFlag = true;														//EndOfFileを検出して
				break;																//ループを抜ける
			}
			if (characterPack != ',' && characterPack != '\n')						//区切りか改行でなければ
			{
				strcat_s(buffer, (const char*)&characterPack);						//strcat_s関数でbufferに連結し、const char関数で書き換える
			}
			else
			{
				num = atoi(buffer);													//atoi関数でbufferをint型に直して、ローカル変数numに代入
				sMap[columnNum][rawNum].GraphicHandle = chipgraphicHandle[num];		//num番目のチップ画像のハンドルを取得
				memset(buffer, 0, sizeof(buffer));									//bufferをリセット
				break;																//区切りか改行なのでループを抜ける
			}
		}
		if (eofFlag)																//1マップ分になったら
		{
			break;																	//ループを抜ける
		}
		if (characterPack == ',')													//区切りを検出したら
		{
			columnNum++;															//列の数を増やす
		}
		if (characterPack == '\n')													//改行だったら
		{
			rawNum++;																//行を増やす
			columnNum = 0;															//列を0にする
		}
	}
	fclose(filePointer);
}

Map::~Map()
{
}

void Map::MapDraw(int scrX,int scrY)
{
	for (int i = 0; i < CELL_NUM_X; i++)
	{
		for (int j = 0; j < CELL_NUM_Y; j++)
		{
			DrawExtendGraph(i * CELL_WIDTH -scrX, j * CELL_HEIGHT- scrY, (i + 1) * CELL_WIDTH-scrX, (j + 1) * CELL_HEIGHT-scrY, sMap[i][j].GraphicHandle, TRUE);
		}
	}
}
