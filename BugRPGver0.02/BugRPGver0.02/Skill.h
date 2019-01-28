#pragma once
#include "Common.h"

void MakeSkillList(SKILL* SkillList) {
	FILE* SkillFile = NULL;
	errno_t err = fopen_s(&SkillFile, "SkillList.txt", "rt");
	if (err != 0) puts("무언가...무언가 잘못됨");
	char line[64];
	int number = 0;
	int count = 0;
	int i = 0;
	while (fgets(line, sizeof(line), SkillFile) != NULL) {
		switch (number % 8) {
		case 0: count = number / 8;
			int i = 0;
			for (i = 0; line[i]; i++) SkillList[count].name[i] = line[i];
			SkillList[count].name[i - 1] = (char)NULL; break;
		case 1: SkillList->San = atoi(line); break;
		case 6: SkillList->Data = atoi(line); break;
		case 7: SkillList->sn = atoi(line); break;
		default: 
			for (int j = 0; line[j]; j++) {SkillList[count].Index[j] = line[j]; i++;}
			SkillList[count].Index[i - 1] = (char)NULL; i--;  break;
		}
		number++;
	}
	fclose(SkillFile);
}

void MakePlayerSkill(PLAYER* player, SKILL* SkillList, int number, int line) {
	player->PlayerSkill[number] = SkillList[line];
}