#pragma once
#include "common.h"

void MakePlayer(PLAYER* player) {
	player->PlayerStatus.Exp = 0;
	player->PlayerStatus.Max_Exp = 10;
	player->PlayerStatus.AC = 0;
	player->PlayerStatus.Gold = 0;
	player->PlayerStatus.Max_HP = 50;
	player->PlayerStatus.HP = player->PlayerStatus.Max_HP;
	player->PlayerStatus.Max_SP = 100;
	player->PlayerStatus.SP = player->PlayerStatus.Max_SP;
	player->PlayerStatus.Level = 1;
	player->PlayerStatus.Str = 5;

	char input[32];

	printf("이름을 입력해주세요 : ");
	scanf_s("%s", input, NAME_SIZE);
	strcpy_s(player->name, NAME_SIZE, input);
	system("cls");
}
