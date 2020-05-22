#include "Skill.h"

void MakeSkillList(SKILL* SkillList) {
	FILE* SkillFile = NULL;
	errno_t err = fopen_s(&SkillFile, "SkillList.txt", "rt");
	if (err != 0) puts("무언가...무언가 잘못됨");
	char line[64] = { 0 };
	int number = 0;
	int count = 0;
	int i = 0;
	int j = 0;
	while (fgets(line, sizeof(line), SkillFile)) {
		switch (number % 6) {
		case 0: count = number / 6;
			for (i = 0; line[i] != '\n'; i++) SkillList[count].name[i] = line[i];
			SkillList[count].name[i] = (char)NULL; break;
		case 5: SkillList[count].SkillNumber = atoi(line); j = 0; break;
		default:
			for (i = 0; line[i] != '\n'; i++, j++) 
				SkillList[count].Index[j] = line[i]; 
			SkillList[count].Index[j] = (char)NULL; break;
		}
		number++;
	}
	fclose(SkillFile);
}

void MakePlayerSkill(PLAYER* player, SKILL* SkillList, int number, int line) {
	player->PlayerSkill[number] = SkillList[line];
}

void MakeMonsterSkill(MONSTER* monster, SKILL* SkillList, int number, int line) {
	monster->MonsterSkill[number] = SkillList[line];
}

void BattleSkill(PLAYER* player, int* skillnumber) {
	int i = 0;
	int j = 0;
	puts("\n\n 취소 : ESC\n");
	puts("skill list : ");
	for (i = 0; player->PlayerSkill[i].SkillNumber != 0; i++) 
		printf("%d. %s\n", i + 1, player->PlayerSkill[i].name);
	while (1) {                                                           
		switch (KI)
		{
		case '1': if (i < 1) puts("스킬이 없다.");
				  else {
			*skillnumber = player->PlayerSkill[0].SkillNumber;
			printf("스킬 : %s를 사용하였다!\n", player->PlayerSkill[0].name); j = 1;
		}break;
		case '2': if (i < 2) puts("스킬이 없다.");
				  else {
			*skillnumber = player->PlayerSkill[1].SkillNumber;
			printf("스킬 : %s를 사용하였다!\n", player->PlayerSkill[1].name); j = 1;
		}break;
		case '3': if (i < 3) puts("스킬이 없다.");
				  else {
			*skillnumber = player->PlayerSkill[2].SkillNumber;
			printf("스킬 : %s를 사용하였다!\n", player->PlayerSkill[2].name); j = 1;
		}break;
		case '4': if (i < 4) puts("스킬이 없다.");
				  else {
			*skillnumber = player->PlayerSkill[3].SkillNumber;
			printf("스킬 : %s를 사용하였다!\n", player->PlayerSkill[3].name); j = 1;
		}break;
		case '5': if (i < 5) puts("스킬이 없다.");
				  else {
			*skillnumber = player->PlayerSkill[4].SkillNumber;
			printf("스킬 : %s를 사용하였다!\n", player->PlayerSkill[4].name); j = 1;
		}break;
		case '6': if (i < 6) puts("스킬이 없다.");
				  else {
			*skillnumber = player->PlayerSkill[5].SkillNumber;
			printf("스킬 : %s를 사용하였다!\n", player->PlayerSkill[5].name); j = 1;
		}break;
		case '7': if (i < 7) puts("스킬이 없다.");
				  else {
			*skillnumber = player->PlayerSkill[6].SkillNumber;
			printf("스킬 : %s를 사용하였다!\n", player->PlayerSkill[6].name); j = 1;
		}break;
		case '8': if (i < 8) puts("스킬이 없다.");
				  else {
			*skillnumber = player->PlayerSkill[7].SkillNumber;
			printf("스킬 : %s를 사용하였다!\n", player->PlayerSkill[7].name); j = 1;
		}break;
		case '9': if (i < 9) puts("스킬이 없다.");
				  else {
			*skillnumber = player->PlayerSkill[8].SkillNumber;
			printf("스킬 : %s를 사용하였다!\n", player->PlayerSkill[8].name); j = 1;
		}break;
		case '0': if (i < 10) puts("스킬이 없다.");
				  else {
			*skillnumber = player->PlayerSkill[9].SkillNumber;
			printf("스킬 : %s를 사용하였다!\n", player->PlayerSkill[9].name); j = 1;
		}break;
		case 27: j = 1;
		default:
			break;
		}
		if (j == 1) break;
	}
}

int FunctionSkill(PLAYER* player, MONSTER* monster, int skillnumber, int constrant) {
	switch (skillnumber) {
	case 1: return DownwardHit(player, monster); break;
	case 2: return StepOn(player, monster); break;
	case 3: return Refreshment(player, monster); break;
	case 4: return Meditation(player, monster); break;
	case 5: return heal(player, monster); break;
	case 6: return death(player, monster, constrant); break;
	default: break;
	}
	return 0;
}