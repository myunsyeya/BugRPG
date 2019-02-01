#pragma once
#include "Common.h"

void MonsterInitialParameter(int count, MONSTER* monster, char* monstername, int Exp, int Def, int Gold, int Max_HP, int Str, int Spd);
void MonsterNameFile(MONSTER* MonsterList);
void MonsterParameterFile(MONSTER* MonsterList);
void MonsterList(MONSTER* MonsterList);
void MonsterMake(MONSTER* Monster, MONSTER* MonsterList, int line, int count);

