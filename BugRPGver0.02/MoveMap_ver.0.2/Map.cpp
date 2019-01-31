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
	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
		{
			if (i == playerpos.y && j == playerpos.x)
				printf("▽");
			else if (map[j][i] == '1')						// 길
				printf("  ");
			else if (map[j][i] == '0')						// 벽
				printf("■");
			else if (map[j][i] == '2')						// 몬스터 스폰
				printf("  ");
		}
		printf("\n");
	}
	system("pause");
}

void PrintMapByPlayer(char map[MAP_SIZE][MAP_SIZE], POS playerpos)
{


	for (int i = playerpos.y - 5; i < playerpos.y + 5; i++)
	{
		for (int j = playerpos.x - 5; j < playerpos.x + 5; j++)
		{
			if (i == playerpos.y && j == playerpos.x)		// 플레이어
				printf("▽");
			else if (map[i][j] == '1')						// 길
				printf("  ");
			else if (map[i][j] == '0')						// 벽
				printf("■");
			else if (map[i][j] == '2')						// 몬스터 스폰
				printf("□");
			else
				printf("  ");
		}
		printf("\n");
	}
}

void MoveMap(char map[MAP_SIZE][MAP_SIZE], POS* playerpos)
{
	char input = _getch();

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
	case 'x':									// 전채맵 확인
		system("cls");
		PrintMapTotal(map, *playerpos);
	default:
		break;
	}

	return;
}

void MoveMapByTemp(char map[MAP_SIZE][MAP_SIZE], POS* player)
{
	POS temp = *player;

	char input = _getch();

	switch (input)
	{
	case 'w':
		temp.y--;
		break;
	case 's':
		temp.y++;
		break;
	case 'd':
		temp.x++;
		break;
	case 'a':
		temp.x--;
		break;
	default:
		PrintMapTotal(map, *player);
		break;
	}
	
	if (map[temp.y][temp.x] != '0')
		*player = temp;

}