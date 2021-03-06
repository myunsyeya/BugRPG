#pragma once
#include "Common.h"
#include "Player.h"
#include "Skill.h"
#include "Item.h"

void PlayerHit(PLAYER* player, MONSTER* monster);
void MonsterHit(PLAYER* player, MONSTER* monster);
int CheckHP(PLAYER* player, MONSTER* monster);
void GiveExp(PLAYER* player, MONSTER* monster);
void DiePlayer(PLAYER* player);
void LevelUP(PLAYER* player, PLAYER Lable);
int CheckWinner(PLAYER* player, PLAYER Lable, MONSTER* monster);
int AttackSpd(PLAYER* player, PLAYER Lable, MONSTER* monster);
void battlestatus(PLAYER* player, MONSTER* monster);
int battle_status(PLAYER* player, PLAYER Lable, MONSTER* monster, int* count, 
	int* skillnumber, int* itemnumber, int* i);
