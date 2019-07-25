#include "Player.h"

void MakePlayerName(PLAYER* player) {
	char input[32];

	printf("이름을 입력해주세요 : ");
	scanf_s("%s", input, NAME_SIZE);
	strcpy_s(player->name, NAME_SIZE, input);
	system("cls");
}

void MakePlayerLable(PLAYER* Lable) {
	FILE* Data = NULL;
	errno_t err = fopen_s(&Data, "PlayerLable.txt", "rt");
	if (err != 0) puts("무언가... 무언가 잘못됨");
	int count = 0;
	char line[5] = { 0 };
	int i = 0;
	int level = 0;
	while (fgets(line, sizeof(line), Data) != NULL) {
		switch (i % 8) {
		case 0: level = i / 8 + 1;
		case 1: Lable->PlayerStatus[level].Max_Exp = atoi(line); break;
		case 2: Lable->PlayerStatus[level].Max_HP = atoi(line); break;
		case 3: Lable->PlayerStatus[level].Max_San = atoi(line); break;
		case 4: Lable->PlayerStatus[level].Str = atoi(line); break;
		case 5: Lable->PlayerStatus[level].Def = atoi(line); break;
		case 6: Lable->PlayerStatus[level].Spd = atoi(line); break;
		default: break;
		}
		i++;
	}
	fclose(Data);
}

void CheckStatus(PLAYER* player, PLAYER Lable, int level) {
	player->Level = level;
	player->PlayerStatus[level] = Lable.PlayerStatus[level];
	player->PlayerStatus[level].HP = player->PlayerStatus[level].Max_HP;
	player->PlayerStatus[level].San = player->PlayerStatus[level].Max_San;
}

void MakePlayer(PLAYER* player, PLAYER Lable) {
	MakePlayerName(player);
	CheckStatus(player, Lable, 1);
	player->PlayerStatus[1].Gold = 0;
}

void CheckAddStatus(PLAYER* player) {
	player->PlayerStatus[player->Level].Str += player->addStatus.Str;
	player->PlayerStatus[player->Level].Def += player->addStatus.Def;
	player->PlayerStatus[player->Level].Spd += player->addStatus.Spd;
	player->PlayerStatus[player->Level].Max_HP += player->addStatus.Max_HP;
	player->PlayerStatus[player->Level].HP += player->addStatus.Max_HP;
	player->PlayerStatus[player->Level].Max_San += player->addStatus.Max_San;
	player->PlayerStatus[player->Level].San += player->addStatus.Max_San;
}