#include "PlayerSkill.h"

int DownwardHit(PLAYER* player, MONSTER* monster) {                             //����ġ��
	if (player->PlayerStatus[player->Level].San >= 4) {
		player->PlayerStatus[player->Level].San -= 4;
		monster->MonsterStatus.HP -= 13;
	}
	else puts("���ŷ��� �����ϴ�");
	return 0;
}

int StepOn(PLAYER* player, MONSTER* monster) {                                  //���
	if (player->PlayerStatus[player->Level].San >= 5) {
		player->PlayerStatus[player->Level].San -= 5;
		monster->MonsterStatus.HP -= player->PlayerStatus[player->Level].Str + 5;
	}
	else puts("���ŷ��� �����ϴ�");
	return 0;
}

int Refreshment(PLAYER* player, MONSTER* monster) {
	if (player->SkillLimit > 1) puts("��Żȸ���� �Ұ����ϴ�.");
	else {
		player->PlayerStatus[player->Level].San +=
			(player->PlayerStatus[player->Level].San + 8 <= player->PlayerStatus[player->Level].Max_San) ?
			8 : player->PlayerStatus[player->Level].Max_San - player->PlayerStatus[player->Level].San;
		player->SkillLimit++;
	}
	return 0;
}

int Meditation(PLAYER* player, MONSTER* monster) {
	(player->PlayerStatus[player->Level].Max_San >= 20) ?
		player->PlayerStatus[player->Level].San = player->PlayerStatus[player->Level].Max_San / 2 :
		puts("���ŷ��� �����ϴ�.");
	return 1;
}

int heal(PLAYER* player, MONSTER* monster) {
	if (player->SkillLimit > 0) puts("ȸ���� �Ұ����ϴ�.");
	else (player->PlayerStatus[player->Level].Max_San >= 30) ?
		player->PlayerStatus[player->Level].HP = player->PlayerStatus[player->Level].Max_HP:
		puts("���ŷ��� �����ϴ�.");
	return 0;
}

int death(PLAYER* player, MONSTER* monster, int constrant) {
	if (constrant > 0) { puts("��Ÿ��"); return 0; }
	else (player->Level > 11) ? monster->MonsterStatus.HP = 0 : puts("������ �����ϴ�.");
	return 15;
}
