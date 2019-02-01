#pragma once
#include "Common.h"

void MakeMap(char map[MAP_SIZE][MAP_SIZE]);
void PrintMapByPlayer(char map[MAP_SIZE][MAP_SIZE], POS playerpos);
void PrintMapTotal(char map[MAP_SIZE][MAP_SIZE], POS playerpos);
void MoveMap(char map[MAP_SIZE][MAP_SIZE], POS* playerpos);