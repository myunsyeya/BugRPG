#include "Map.h"

void MakeMap(char map[MAP_SIZE][MAP_SIZE])
{
	FILE* pfile = NULL;
	fopen_s(&pfile, "map.txt", "r");
	if (pfile == NULL)
	{
		fprintf(stderr, "fopen_s error\n");
		exit(1);
	}
	int i = 0;
	int j = 0;
	char temp;
	while (!feof(pfile))
	{
		if ((temp = fgetc(pfile)) != '\n')
		{
			map[i][j] = temp;
			j++;
		}
		else
		{
			i++;
			j = 0;
		}
	}
	fclose(pfile);
}

void PrintMapTotal(char map[MAP_SIZE][MAP_SIZE], POS playerpos)
{
	for (int j = 0; j < MAP_SIZE; j++)
	{
		for (int i = 0; i < MAP_SIZE; i++)
		{
			if (i == playerpos.x && j == playerpos.y)
				printf("▽");
			else if (map[j][i] == '1')						// 길
				printf("  ");
			else if (map[j][i] == '0')						// 벽
				printf("■");
			else if (map[j][i] == '2')						// 몬스터 스폰
				printf("□");
			else if (map[i][j] == '3')                      // 상점
				printf("▣");
		}
		printf("\n");
	}
	system("pause");
}

void PrintMapByPlayer(char map[MAP_SIZE][MAP_SIZE], POS playerpos)
{
	for (int i = playerpos.y - 7; i < playerpos.y + 7; i++)
	{
		for (int j = playerpos.x - 7; j < playerpos.x + 7; j++)
		{
			if (i == playerpos.y && j == playerpos.x)		// 플레이어
				printf("▽");
			else if (map[i][j] == '1')						// 길
				printf("  ");
			else if (map[i][j] == '0')						// 벽
				printf("■");
			else if (map[i][j] == '2')						// 몬스터 스폰
				printf("□");
			else if (map[i][j] == '3')                      // 상점
				printf("▣");
			else
				printf("  ");
		}
		printf("\n");
	}
}

void MoveMap(char map[MAP_SIZE][MAP_SIZE], POS* playerpos, int input)
{
	switch (input)
	{
	case 'w':
		if (map[playerpos->y - 1][playerpos->x] != '0')
			playerpos->y--;
		break;
	case 'a':
		if (map[playerpos->y][playerpos->x - 1] != '0')
			playerpos->x--;
		break;
	case 's':
		if (map[playerpos->y + 1][playerpos->x] != '0')
			playerpos->y++;
		break;
	case 'd':
		if (map[playerpos->y][playerpos->x + 1] != '0')
			playerpos->x++;
		break;
	case 'x':									// 전체맵 확인
		system("cls");
		PrintMapTotal(map, *playerpos);
	default:
		break;
	}
}
