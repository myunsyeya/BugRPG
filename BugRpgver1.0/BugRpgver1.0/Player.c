#include "Player.h"

void MakePlayerName(PLAYER* player) {
	char input[32];

	printf("�̸��� �Է����ּ��� : ");
	scanf_s("%s", input, NAME_SIZE);
	strcpy_s(player->name, NAME_SIZE, input);
	system("cls");
}

void MakePlayerLable(PLAYER* Lable) {
	FILE* Data = NULL;
	errno_t err = fopen_s(&Data, "PlayerLable.txt", "rt");
	if (err != 0) puts("����... ���� �߸���");
	int count = 0;
	char line[5];
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

void PlayerStatusByLevel(PLAYER* player, PLAYER Lable, int level) {
	player->Level = level;
	player->PlayerStatus[level] = Lable.PlayerStatus[level];
	player->PlayerStatus[level].Exp = 0;
	player->PlayerStatus[level].HP = player->PlayerStatus[level].Max_HP;
	player->PlayerStatus[level].San = player->PlayerStatus[level].Max_San;
}

void MakePlayer(PLAYER* player, PLAYER Lable) {
	MakePlayerName(player);
	PlayerStatusByLevel(player, Lable, 1);
	player->PlayerStatus[1].Gold = 0;
}

void AddStatusSave(PLAYER* player, PLAYER* addstatus, PLAYER Lable) {
	addstatus->PlayerStatus[player->Level].Str = player->PlayerStatus[player->Level].Str - Lable.PlayerStatus[player->Level].Str;
	addstatus->PlayerStatus[player->Level].Def = player->PlayerStatus[player->Level].Def - Lable.PlayerStatus[player->Level].Def;
	addstatus->PlayerStatus[player->Level].Spd = player->PlayerStatus[player->Level].Spd - Lable.PlayerStatus[player->Level].Spd;
	addstatus->PlayerStatus[player->Level].Max_HP = player->PlayerStatus[player->Level].Max_HP - Lable.PlayerStatus[player->Level].Max_HP;
	addstatus->PlayerStatus[player->Level].Max_San = player->PlayerStatus[player->Level].Max_San - Lable.PlayerStatus[player->Level].Max_San;
}

void AddStatusApply(PLAYER* player, PLAYER* addstatus) {
	player->addStatus.Str = addstatus->PlayerStatus[player->Level].Str;
	player->addStatus.Def = addstatus->PlayerStatus[player->Level].Def;
	player->addStatus.Spd = addstatus->PlayerStatus[player->Level].Spd;
	player->addStatus.Max_HP = addstatus->PlayerStatus[player->Level].Max_HP;
	player->addStatus.Max_San = addstatus->PlayerStatus[player->Level].Max_San;
	memset(&addstatus, 0, sizeof(addstatus));
}

void CheckStatus(PLAYER* player, PLAYER Lable) {
	player->PlayerStatus[player->Level] = Lable.PlayerStatus[player->Level];
	player->PlayerStatus[player->Level].Str += player->addStatus.Str;
	player->PlayerStatus[player->Level].Def += player->addStatus.Def;
	player->PlayerStatus[player->Level].Spd += player->addStatus.Spd;
	player->PlayerStatus[player->Level].Max_HP += player->addStatus.Max_HP;
	player->PlayerStatus[player->Level].Max_San += player->addStatus.Max_San;
	memset(&player->addStatus, 0, sizeof(player->addStatus));
}