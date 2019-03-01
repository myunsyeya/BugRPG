#include "Skill.h"

void MakeSkillList(SKILL* SkillList) {
	FILE* SkillFile = NULL;
	errno_t err = fopen_s(&SkillFile, "SkillList.txt", "rt");
	if (err != 0) puts("무언가...무언가 잘못됨");
	char line[64];
	int number = 0;
	int count = 0;
	int i = 0;
	int j = 0;
	while (fgets(line, sizeof(line), SkillFile)) {
		switch (number % 6) {
		case 0: count = number / 6;
			for (i = 0; line[i]; i++) SkillList[count].name[i] = line[i];
			SkillList[count].name[i - 1] = (char)NULL; break;
		case 5: SkillList[count].SkillNumber = atoi(line); j = 0; break;
		default:
			for (i = 0; line[i]; i++) { SkillList[count].Index[j] = line[i]; j++; } 
			j--; SkillList[count].Index[j] = (char)NULL; break;
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
	puts("\n\n 취소 : ESC\n");
	puts("skill list : ");
	for (i = 0; player->PlayerSkill[i].SkillNumber != 0; i++) 
		printf("%d. %s\n", i + 1, player->PlayerSkill[i].name);
	while (KI != 13) {                                                           //ENTER
		switch (KI)
		{
		case '1': if (i < 1) puts("스킬이 없다.");
				  else {
			*skillnumber = player->PlayerSkill[0].SkillNumber;
			printf("스킬 : %s를 사용하였다!", player->PlayerSkill[0].name);
		}break;
		case '2': if (i < 2) puts("스킬이 없다.");
				  else {
			*skillnumber = player->PlayerSkill[1].SkillNumber;
			printf("스킬 : %s를 사용하였다!", player->PlayerSkill[1].name);
		}break;
		case '3': if (i < 3) puts("스킬이 없다.");
				  else {
			*skillnumber = player->PlayerSkill[2].SkillNumber;
			printf("스킬 : %s를 사용하였다!", player->PlayerSkill[2].name);
		}break;
		case '4': if (i < 4) puts("스킬이 없다.");
				  else {
			*skillnumber = player->PlayerSkill[3].SkillNumber;
			printf("스킬 : %s를 사용하였다!", player->PlayerSkill[3].name);
		}break;
		case '5': if (i < 5) puts("스킬이 없다.");
				  else {
			*skillnumber = player->PlayerSkill[4].SkillNumber;
			printf("스킬 : %s를 사용하였다!", player->PlayerSkill[4].name);
		}break;
		case '6': if (i < 6) puts("스킬이 없다.");
				  else {
			*skillnumber = player->PlayerSkill[5].SkillNumber;
			printf("스킬 : %s를 사용하였다!", player->PlayerSkill[5].name);
		}break;
		case '7': if (i < 7) puts("스킬이 없다.");
				  else {
			*skillnumber = player->PlayerSkill[6].SkillNumber;
			printf("스킬 : %s를 사용하였다!", player->PlayerSkill[6].name);
		}break;
		case '8': if (i < 8) puts("스킬이 없다.");
				  else {
			*skillnumber = player->PlayerSkill[7].SkillNumber;
			printf("스킬 : %s를 사용하였다!", player->PlayerSkill[7].name);
		}break;
		case '9': if (i < 9) puts("스킬이 없다.");
				  else {
			*skillnumber = player->PlayerSkill[8].SkillNumber;
			printf("스킬 : %s를 사용하였다!", player->PlayerSkill[8].name);
		}break;
		case '0': if (i < 10) puts("스킬이 없다.");
				  else {
			*skillnumber = player->PlayerSkill[9].SkillNumber;
			printf("스킬 : %s를 사용하였다!", player->PlayerSkill[9].name);
		}break;
		default:
			break;
		}
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