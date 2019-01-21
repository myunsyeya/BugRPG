#pragma once
#include "common.h"

void MonsterInitialParameter(int count, MONSTER* monster[], char monstername[], int Exp, int AC, int Gold, int Max_HP, int Level, int Str) {
	for (int i = 0; i < count; i++) {
		strcpy_s(monster[i]->name, 32, monstername);
		monster[i]->MonsterStatus.Exp = Exp;
		monster[i]->MonsterStatus.AC = AC;
		monster[i]->MonsterStatus.Gold = Gold;
		monster[i]->MonsterStatus.Max_HP = Max_HP;
		monster[i]->MonsterStatus.HP = Max_HP;
		monster[i]->MonsterStatus.Level = Level;
		monster[i]->MonsterStatus.Str = Str;
	}
}

void MonsterNameFile(MONSTER* MonsterList) {
	FILE* monsterfile = NULL;
	errno_t err = fopen_s(&monsterfile, "MonsterNameFile.txt", "rt");
	if (err != 0) puts("무언가... 무언가 잘못됨");
	int count = 0;
	char line[NAME_SIZE];
	while (fgets(line, sizeof(line), monsterfile) != NULL) count++;
	MonsterList[count];
	count = 0;
	while (fgets(line, sizeof(line), monsterfile) != NULL) {
		strcpy_s(MonsterList[count].name, NAME_SIZE, line);
		count++;
	}
	fclose(monsterfile);
}

void MonsterParameterFile(MONSTER* MonsterList) {
	FILE* monsterfile = NULL;
	errno_t err = fopen_s(&monsterfile, "MonsterParameterFile.txt", "rt");
	if (err != 0) puts("무언가... 무언가 잘못됨");
	char number[Parameternumber];
	int i = 0;
	while (fgets(number, sizeof(number), monsterfile) != NULL) {
		int n = i / 8;
		switch (i % 8) {
		case 1: MonsterList[n].MonsterStatus.Exp = atoi(number); break;
		case 2: MonsterList[n].MonsterStatus.AC = atoi(number); break;
		case 3: MonsterList[n].MonsterStatus.Gold = atoi(number); break;
		case 4: MonsterList[n].MonsterStatus.Max_HP = atoi(number); break;
		case 5: MonsterList[n].MonsterStatus.Level = atoi(number); break;
		case 6: MonsterList[n].MonsterStatus.Str = atoi(number); break;
		default: break;
		}
		i++;
	}
	fclose(monsterfile);
}

void MonsterList(MONSTER* MonsterList) {
	MonsterNameFile(MonsterList);
	MonsterParameterFile(MonsterList);
}

void MonsterMake(MONSTER* Monster[], MONSTER* MonsterList, int line, int count) {
	for (int i = 0; i < count; i++) {
		strcpy_s(Monster[i]->name, NAME_SIZE, MonsterList[line].name);
		Monster[i]->MonsterStatus.Exp = MonsterList[line].MonsterStatus.Exp;
		Monster[i]->MonsterStatus.AC = MonsterList[line].MonsterStatus.AC;
		Monster[i]->MonsterStatus.Gold = MonsterList[line].MonsterStatus.Gold;
		Monster[i]->MonsterStatus.Max_HP = MonsterList[line].MonsterStatus.HP;
		Monster[i]->MonsterStatus.HP = Monster[i]->MonsterStatus.Max_HP;
		Monster[i]->MonsterStatus.Level = MonsterList[line].MonsterStatus.Level;
		Monster[i]->MonsterStatus.Str = MonsterList[line].MonsterStatus.Str;
	}
}