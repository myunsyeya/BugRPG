#pragma once
#include "common.h"

#define MAP_SIZE 64

typedef struct position
{
	int x;
	int y;
}POS;

void MakeMap(char map[MAP_SIZE][MAP_SIZE]);

void PrintMapByPlayer(char map[MAP_SIZE][MAP_SIZE], POS playerpos);

void PrintMapTotal(char map[MAP_SIZE][MAP_SIZE], POS playerpos);

void MoveMap(char map[MAP_SIZE][MAP_SIZE], POS* playerpos);

void MoveMapByTemp(char map[MAP_SIZE][MAP_SIZE], POS* player);

