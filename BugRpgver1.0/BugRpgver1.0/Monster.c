#include "Monster.h"

//void MonsterInitialParameter(int count, MONSTER* monster, char* monstername, int Exp, int Def, int Gold, int Max_HP, int Str, int Spd) {
//	for (int i = 0; i < count; i++) {
//		strcpy_s(monster[i].name, NAME_SIZE, monstername);
//		monster[i].MonsterStatus.Exp = Exp;
//		monster[i].MonsterStatus.Def = Def;
//		monster[i].MonsterStatus.Gold = Gold;
//		monster[i].MonsterStatus.Max_HP = Max_HP;
//		monster[i].MonsterStatus.HP = Max_HP;
//		monster[i].MonsterStatus.Str = Str;
//		monster[i].MonsterStatus.Spd = Spd;
//	}
//}

void MonsterNameFile(MONSTER* MonsterList) {
	FILE* monsterfile = NULL;
	errno_t err = fopen_s(&monsterfile, "MonsterNameFile.txt", "rt");
	char line[NAME_SIZE];
	int count = 0;
	int i = 0;
	if (err != 0) puts("무언가... 무언가 잘못됨");
	while (fgets(line, sizeof(line), monsterfile)) {
		for (i = 0; line[i]; i++) MonsterList[count].name[i] = line[i];
		MonsterList[count].name[i - 1] = (char)NULL;
		count++;
	}
	fclose(monsterfile);
}

void MonsterParameterFile(MONSTER* MonsterList) {
	FILE* monsterfile = NULL;
	errno_t err = fopen_s(&monsterfile, "MonsterParameterFile.txt", "rt");
	if (err != 0) puts("무언가... 무언가 잘못됨");
	char line[5];
	int i = 0;
	int n = 0;
	while (fgets(line, sizeof(line), monsterfile) != NULL) {
		switch (i % 8) {
		case 0: n = i / 8;
		case 1: MonsterList[n].MonsterStatus.Exp = atoi(line); break;
		case 2: MonsterList[n].MonsterStatus.Def = atoi(line); break;
		case 3: MonsterList[n].MonsterStatus.Gold = atoi(line); break;
		case 4: MonsterList[n].MonsterStatus.Max_HP = atoi(line); break;
		case 5: MonsterList[n].MonsterStatus.Str = atoi(line); break;
		case 6: MonsterList[n].MonsterStatus.Spd = atoi(line); break;
		default: break;
		}
		i++;
	}
	fclose(monsterfile);
}

void MakeMonsterList(MONSTER* MonsterList) {
	MonsterNameFile(MonsterList);
	MonsterParameterFile(MonsterList);
}

void MakeMonster(MONSTER* Monster, MONSTER* MonsterList, int line) {
		*Monster = MonsterList[line];
		Monster->MonsterStatus.HP = Monster->MonsterStatus.Max_HP;
}