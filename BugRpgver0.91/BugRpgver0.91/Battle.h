#pragma once
#include "Common.h"

void PlayerHit(PLAYER* player, MONSTER* monster);
void MonsterHit(PLAYER* player, MONSTER* monster);
int CheckHP(PLAYER* player, MONSTER* monster);
void BattlebyCheckSpd(PLAYER* player, MONSTER* monster);
