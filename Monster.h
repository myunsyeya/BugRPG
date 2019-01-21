#pragma once
#include "common.h"

void MonsterInitialParameter(int count, MONSTER* monster, char monstername[], int Exp, int AC, int Gold, int Max_HP, int Level, int Str) {
	strcpy_s(monster->name, 32, monstername);
	monster->MonsterStatus.Exp = Exp;
	monster->MonsterStatus.AC = AC;
	monster->MonsterStatus.Gold = Gold;
	monster->MonsterStatus.Max_HP = Max_HP;
	monster->MonsterStatus.HP = Max_HP;
	monster->MonsterStatus.Level = Level;
	monster->MonsterStatus.Str = Str;
}

void MonsterNameFile(MONSTER* MonsterList[]) {
	FILE* monsterfile;
	errno_t err = fopen_s(&monsterfile, "MonsterNameFile.txt", "rt");
	if (err != 0)puts("무언가... 무언가 잘못됨");
	int count = 0;
	char line[NAME_SIZE];
	while (fgets(line, sizeof(line), monsterfile) != NULL) count++;
	MonsterList[count];
	count = 0;
	while (fgets(line, sizeof(line), monsterfile) != NULL) {
		strcpy_s(MonsterList[count]->name, NAME_SIZE, line);
		count++;
	}
	fclose(monsterfile);
}

void MonsterParameterFile(MONSTER* MonsterList[]) {
	FILE* monsterfile;
	errno_t err = fopen_s(&monsterfile, "MonsterParameterFile.txt", "rt");
	if (err != 0)puts("무언가... 무언가 잘못됨");
	char number[Parameternumber];
	int i = 0;
	while (fgets(number, sizeof(number), monsterfile) != NULL) {
		int n = i / 8;
		switch (i % 8) {
		case 1: MonsterList[n]->MonsterStatus.Exp = atoi(number); break;
		case 2: MonsterList[n]->MonsterStatus.AC = atoi(number); break;
		case 3: MonsterList[n]->MonsterStatus.Gold = atoi(number); break;
		case 4: MonsterList[n]->MonsterStatus.Max_HP = atoi(number); break;
		case 5: MonsterList[n]->MonsterStatus.Level = atoi(number); break;
		case 6: MonsterList[n]->MonsterStatus.Str = atoi(number); break;
		default: break;
		}
		i++;
	}
	fclose(monsterfile);
}

void MonsterMake(MONSTER* MonsterList[], int line, int count) {
	MonsterNameFile(MonsterList);
	MonsterParameterFile(MonsterList);
	*(MonsterList[line] + count);
}