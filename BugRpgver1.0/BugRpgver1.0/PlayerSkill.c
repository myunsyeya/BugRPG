#include "PlayerSkill.h"

int DownwardHit(PLAYER* player, MONSTER* monster) {                             //내려치기
	if (player->PlayerStatus[player->Level].San >= 4) {
		player->PlayerStatus[player->Level].San -= 4;
		monster->MonsterStatus.HP -= 13;
	}
	else puts("정신력이 부족하다");
	return 0;
}

int StepOn(PLAYER* player, MONSTER* monster) {                                  //밟기
	if (player->PlayerStatus[player->Level].San >= 5) {
		player->PlayerStatus[player->Level].San -= 5;
		monster->MonsterStatus.HP -= player->PlayerStatus[player->Level].Str + 5;
	}
	else puts("정신력이 부족하다");
	return 0;
}

int Refreshment(PLAYER* player, MONSTER* monster) {
	if (player->SkillLimit > 1) puts("멘탈회복이 불가능하다.");
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
		puts("정신력이 부족하다.");
	return 1;
}

int heal(PLAYER* player, MONSTER* monster) {
	if (player->SkillLimit > 0) puts("회복이 불가능하다.");
	else (player->PlayerStatus[player->Level].Max_San >= 30) ?
		player->PlayerStatus[player->Level].HP = player->PlayerStatus[player->Level].Max_HP:
		puts("정신력이 부족하다.");
	return 0;
}

int death(PLAYER* player, MONSTER* monster, int constrant) {
	if (constrant > 0) { puts("쿨타임"); return 0; }
	else (player->Level > 11) ? monster->MonsterStatus.HP = 0 : puts("레벨이 부족하다.");
	return 15;
}
