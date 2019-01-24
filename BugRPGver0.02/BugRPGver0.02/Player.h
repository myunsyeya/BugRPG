#pragma once
#include "common.h"

void MakePlayerName(PLAYER* player) {
	char input[32];

	printf("이름을 입력해주세요 : ");
	scanf_s("%s", input, NAME_SIZE);
	strcpy_s(player->name, NAME_SIZE, input);
	system("cls");
}

void PlayerLable(PLAYER* Lable) {
	FILE* Data = NULL;
	errno_t err = fopen_s(&Data, "PlayerLable.txt", "rt");
	if (err != 0) puts("무언가... 무언가 잘못됨");
	int count = 0;
	char number[Parameternumber];
	int i = 0;
	int level = 0;
	while (fgets(number, sizeof(number), Data) != NULL) {
		switch (i % 8) {
		case 0: level = i / 8 + 1;
		case 1: Lable->PlayerStatus.Max_Exp[level] = atoi(number); break;
		case 2: Lable->PlayerStatus.Max_HP[level] = atoi(number); break;
		case 3: Lable->PlayerStatus.Max_San[level] = atoi(number); break;
		case 4: Lable->PlayerStatus.Str[level]= atoi(number); break;
		case 5: Lable->PlayerStatus.Def[level]= atoi(number); break;
		case 6: Lable->PlayerStatus.Spd[level]= atoi(number); break;
		Default: break;
		}
		i++;
	}
	fclose(Data);
}

void PlayerStatusByLevel(PLAYER* player, PLAYER Lable, int level) {
	player->PlayerStatus.Level = level;
	player->PlayerStatus.Max_Exp[level] = Lable.PlayerStatus.Max_Exp[level];
	player->PlayerStatus.Exp = player->PlayerStatus.Max_Exp[level];
	player->PlayerStatus.Max_HP[level] = Lable.PlayerStatus.Max_HP[level];
	player->PlayerStatus.HP = player->PlayerStatus.Max_HP[level];
	player->PlayerStatus.Max_San[level] = Lable.PlayerStatus.Max_San[level];
	player->PlayerStatus.San = player->PlayerStatus.Max_San[level];
	player->PlayerStatus.Str[level] = Lable.PlayerStatus.Str[level];
	player->PlayerStatus.Def[level] = Lable.PlayerStatus.Def[level];
	player->PlayerStatus.Spd[level] = Lable.PlayerStatus.Spd[level];
}
void MakePlayer(PLAYER* player, PLAYER Lable) {
	MakePlayerName(player);
	int level = 1;
	PlayerStatusByLevel(player, Lable, level);
}