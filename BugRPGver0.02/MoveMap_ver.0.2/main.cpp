#include <stdio.h>
#include "Map.h"

int main()
{
	char map[MAP_SIZE][MAP_SIZE] = {0};
	POS player;

	player.x = 25;
	player.y = 5;
	MakeMap(map);
	
	while (true)
	{
		system("cls");
		PrintMapByPlayer(map, player);
		MoveMap(map, &player);
	}

	return 0;
}