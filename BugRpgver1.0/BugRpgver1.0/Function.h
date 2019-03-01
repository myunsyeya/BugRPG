#pragma once
#include "Common.h"
#include "Menu.h"
#include "Monster.h"
#include "Player.h"
#include "SKill.h"
#include "Item.h"
#include "Battle.h"
#include "Map.h"

void init();
int back_graund(PLAYER* player, POS* playerpos, char map[MAP_SIZE][MAP_SIZE], int life);
void battle_ground(PLAYER* player, PLAYER Lable, POS* playerpos, char map[MAP_SIZE][MAP_SIZE], MONSTER monster, MONSTER* list, ITEM* ItemList, int* life);