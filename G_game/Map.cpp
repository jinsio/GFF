#include "Map.h"

Map::Map()
	:mapPos()
{
	LoadDivGraph("assets/mapArufa/mapsozai.png",  (160 / 32)* (32 / 32), 160 / 32,  32, 32, 32, chipgraphicHandle);
	FILE* filePointer;
	fopen_s(&filePointer, "assets/mapArufa/Maoumap_map.csv", "r");																//fopen_s�֐���map.csv��ǂݎ��`���ŊJ��
	if (filePointer == NULL)																			//filePointer����̏ꍇ��
	{
		DebugBreak();																					//�f�o�b�O���~
	}
	memset(buffer, 0, sizeof(buffer));																	//memset�֐��Ń�������buffer���Z�b�g���Asizeof���Z�q�ŗv�f�������߂�

	while (1)
	{
		while (1)
		{
			characterPack = fgetc(filePointer);										//fgetc�֐���filepointer���當����ǂ��characterPack�Ɋi�[
			if (characterPack == EOF)
			{
				eofFlag = true;														//EndOfFile�����o����
				break;																//���[�v�𔲂���
			}
			if (characterPack != ',' && characterPack != '\n')						//��؂肩���s�łȂ����
			{
				strcat_s(buffer, (const char*)&characterPack);						//strcat_s�֐���buffer�ɘA�����Aconst char�֐��ŏ���������
			}
			else
			{
				num = atoi(buffer);													//atoi�֐���buffer��int�^�ɒ����āA���[�J���ϐ�num�ɑ��
				sMap[columnNum][rawNum].GraphicHandle = chipgraphicHandle[num];		//num�Ԗڂ̃`�b�v�摜�̃n���h�����擾
				memset(buffer, 0, sizeof(buffer));									//buffer�����Z�b�g
				break;																//��؂肩���s�Ȃ̂Ń��[�v�𔲂���
			}
		}
		if (eofFlag)																//1�}�b�v���ɂȂ�����
		{
			break;																	//���[�v�𔲂���
		}
		if (characterPack == ',')													//��؂�����o������
		{
			columnNum++;															//��̐��𑝂₷
		}
		if (characterPack == '\n')													//���s��������
		{
			rawNum++;																//�s�𑝂₷
			columnNum = 0;															//���0�ɂ���
		}
	}
	fclose(filePointer);
}

Map::~Map()
{
}

void Map::MapDraw()
{
	for (int i = 0; i < CELL_NUM_X; i++)
	{
		for (int j = 0; j < CELL_NUM_Y; j++)
		{
			DrawExtendGraph(i * CELL_WIDTH + mapPos.x, j * CELL_HEIGHT+ mapPos.y, (i + 1) * CELL_WIDTH + mapPos.x, (j + 1) * CELL_HEIGHT+ mapPos.y, sMap[i][j].GraphicHandle, TRUE);
		}
	}
}
