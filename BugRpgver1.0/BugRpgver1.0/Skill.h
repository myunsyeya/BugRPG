#pragma once
#include "Common.h"
#include "MonsterSkill.h"
#include "PlayerSkill.h"

void MakeSkillList(SKILL* SkillList);
void MakePlayerSkill(PLAYER* player, SKILL* SkillList, int number, int line);
void MakeMonsterSkill(MONSTER* monster, SKILL* SkillList, int number, int line);
void BattleSkill(PLAYER* player, int* skillnumber);
int FunctionSkill(PLAYER* player, MONSTER* monster, int skillnumber, int constrant);