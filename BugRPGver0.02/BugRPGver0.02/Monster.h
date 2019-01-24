#pragma once
#include "common.h"

void MonsterInitialParameter(int count, MONSTER* monster[], char monstername[], int Exp, int Def, int Gold, int Max_HP, int Str, int Spd) {
	for (int i = 0; i < count; i++) {
		strcpy_s(monster[i]->name, 32, monstername);
		monster[i]->Exp = Exp;
		monster[i]->Def = Def;
		monster[i]->Gold = Gold;
		monster[i]->Max_HP = Max_HP;
		monster[i]->HP = Max_HP;
		monster[i]->Str = Str;
		monster[i]->Spd = Spd;
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
		case 1: MonsterList[n].Exp = atoi(number); break;
		case 2: MonsterList[n].Def = atoi(number); break;
		case 3: MonsterList[n].Gold = atoi(number); break;
		case 4: MonsterList[n].Max_HP = atoi(number); break;
		case 5: MonsterList[n].Str = atoi(number); break;
		case 6: MonsterList[n].Spd = atoi(number); break;
		Default: break;
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
		Monster[i]->Exp = MonsterList[line].Exp;
		Monster[i]->Def = MonsterList[line].Def;
		Monster[i]->Gold = MonsterList[line].Gold;
		Monster[i]->Max_HP = MonsterList[line].HP;
		Monster[i]->HP = Monster[i]->Max_HP;
		Monster[i]->Str = MonsterList[line].Str;
		Monster[i]->Spd = MonsterList[line].Spd;
	}
}