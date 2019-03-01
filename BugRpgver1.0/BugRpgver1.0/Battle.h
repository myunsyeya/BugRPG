#pragma once
#include "Common.h"
#include "Player.h"

void PlayerHit(PLAYER* player, MONSTER* monster);
void MonsterHit(PLAYER* player, MONSTER* monster);
int CheckHP(PLAYER* player, MONSTER* monster);
void GiveExp(PLAYER* player, MONSTER* monster);
void DiePlayer(PLAYER* player);
void LevelUP(PLAYER* player, PLAYER Lable);
int CheckWinner(PLAYER* player, PLAYER Lable, MONSTER* monster);
int AttackSpd(PLAYER* player, PLAYER Lable, MONSTER* monster, int* life);
void battlestatus(PLAYER* player, MONSTER* monster);
int battle_status(PLAYER* player, PLAYER Lable, MONSTER* monster, int* life, int* count, int* skillnumber, int* i);
