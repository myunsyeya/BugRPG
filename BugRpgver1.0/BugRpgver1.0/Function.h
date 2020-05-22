#pragma once
#include "Common.h"
#include "Menu.h"
#include "Monster.h"
#include "Player.h"
#include "SKill.h"
#include "Item.h"
#include "Battle.h"
#include "Map.h"

void initialize(PLAYER* Player, PLAYER* PlayerLable, MONSTER* Monster, MONSTER* MonsterList, 
	SKILL* SkillList, ITEM* ItemList, POS* PlayerPos, char Map[MAP_SIZE][MAP_SIZE]);
void init();
int back_graund(PLAYER* player, POS* playerPos, char map[MAP_SIZE][MAP_SIZE]);
void battle_ground(PLAYER* player, PLAYER Lable, POS* playerPos, char map[MAP_SIZE][MAP_SIZE], 
	MONSTER monster, MONSTER* monsterList, ITEM* ItemList);
void freeAll(PLAYER* Player, PLAYER* PlayerLable, MONSTER* Monster, MONSTER* MonsterList,
	SKILL* SkillList, ITEM* ItemList, POS* PlayerPos);