#include "Item.h"

void MakeItemList(ITEM* ItemList) {
	FILE* ItemFile = NULL;
	errno_t err = fopen_s(&ItemFile, "ItemList.txt", "rt");
	if (err != 0) puts("무언가...무언가 잘못됨");
	char line[64] = { 0 };
	int number = 0;
	int count = 0;
	int i = 0;
	int j = 0;
	while (fgets(line, sizeof(line), ItemFile)) {
		switch (number % 11) {
		case 0: count = number / 11;
			for (i = 0; line[i]; i++) ItemList[count].name[i] = line[i];
			ItemList[count].name[i - 1] = (char)NULL; break;
			j = 0;
		case 1: ItemList[count].ItemStatus.HP = atoi(line); break;
		case 2: ItemList[count].ItemStatus.San = atoi(line); break;
		case 3: ItemList[count].ItemStatus.Str = atoi(line); break;
		case 4: ItemList[count].ItemStatus.Def = atoi(line); break;
		case 5: ItemList[count].ItemStatus.Gold = atoi(line); break;
		case 6: ItemList[count].itemnumber = atoi(line); break;
		default: 
			for (i = 0; line[i]; i++) { ItemList[count].info[j] = line[i]; j++; }
			j--; ItemList[count].info[j] = (char)NULL; break;
		}
		number++;
	}
	fclose(ItemFile);
}

void MakePlayerItem(PLAYER* player, ITEM* ItemList, int number, int line) {
	player->inventory[number] = ItemList[line];
}

void InstallPlayerEquipment(PLAYER* player, int number) {
	player->inventory[number].itemnumber = player->equipment;	
}

void BattleItem(PLAYER* player, int* itemnumber) {
	int i = 0;
	int j = 0;
	puts("\n\n 취소 : ESC\n");
	puts("item list : ");
	for (i = 0; player->inventory[i].itemnumber != 0; i++)
		printf("%d. %s\n", i + 1, player->inventory[i].name);
	while (1) {
		switch (KI)
		{
		case '1': if (i < 1) puts("아이템이 없다.");
				  else if (player->inventory[0].itemnumber > 5) puts("배틀 중엔 장비를 착용할 수 없다.");
				  else {
			*itemnumber = player->inventory[0].itemnumber;
			printf("아이템 : %s를 사용하였다!\n", player->inventory[0].name);
			memset(&player->inventory[0], 0, sizeof(player->inventory[0])); j = 1;
		}break;
		case '2': if (i < 2) puts("아이템이 없다.");
				  else if (player->inventory[1].itemnumber > 5) puts("배틀 중엔 장비를 착용할 수 없다.");
				  else {
			*itemnumber = player->inventory[1].itemnumber;
			printf("아이템 : %s를 사용하였다!\n", player->inventory[1].name);
			memset(&player->inventory[1], 0, sizeof(player->inventory[1])); j = 1;
		}break;
		case '3': if (i < 3) puts("아이템이 없다.");
				  else if (player->inventory[2].itemnumber > 5) puts("배틀 중엔 장비를 착용할 수 없다.");
				  else {
			*itemnumber = player->inventory[2].itemnumber;
			printf("아이템 : %s를 사용하였다!\n", player->inventory[2].name);
			memset(&player->inventory[2], 0, sizeof(player->inventory[2])); j = 1;
		}break;
		case '4': if (i < 4) puts("아이템이 없다.");
				  else if (player->inventory[3].itemnumber > 5) puts("배틀 중엔 장비를 착용할 수 없다.");
				  else {
			*itemnumber = player->inventory[3].itemnumber;
			printf("아이템 : %s를 사용하였다!\n", player->inventory[3].name);
			memset(&player->inventory[3], 0, sizeof(player->inventory[3])); j = 1;
		}break;
		case '5': if (i < 5) puts("아이템이 없다.");
				  else if (player->inventory[4].itemnumber > 5) puts("배틀 중엔 장비를 착용할 수 없다.");
				  else {
			*itemnumber = player->inventory[4].itemnumber;
			printf("아이템 : %s를 사용하였다!\n", player->inventory[4].name);
			memset(&player->inventory[4], 0, sizeof(player->inventory[4])); j = 1;
		}break;
		case 27: j = 1;
		default:
			break;
		}
		if (j == 1) break;
	}
}

void FunctionItem(PLAYER* player, ITEM* ItemList, int itemnumber) {
	switch (itemnumber)
	{
	case 1: 
		player->PlayerStatus[player->Level].HP += ItemList[0].ItemStatus.HP;
		player->PlayerStatus[player->Level].Str += ItemList[0].ItemStatus.Str;
		player->PlayerStatus[player->Level].Def += ItemList[0].ItemStatus.Def;
		break;
	case 2:
		player->PlayerStatus[player->Level].HP += ItemList[1].ItemStatus.HP;
		player->PlayerStatus[player->Level].Str += ItemList[1].ItemStatus.Str;
		player->PlayerStatus[player->Level].Def += ItemList[1].ItemStatus.Def;
		break;
	case 3:
		player->PlayerStatus[player->Level].HP += ItemList[2].ItemStatus.HP;
		player->PlayerStatus[player->Level].Str += ItemList[2].ItemStatus.Str;
		player->PlayerStatus[player->Level].Def += ItemList[2].ItemStatus.Def;
		break;
	case 4:
		player->PlayerStatus[player->Level].HP += ItemList[3].ItemStatus.HP;
		player->PlayerStatus[player->Level].Str += ItemList[3].ItemStatus.Str;
		player->PlayerStatus[player->Level].Def += ItemList[3].ItemStatus.Def;
		break;
	case 5:
		player->PlayerStatus[player->Level].HP += ItemList[4].ItemStatus.HP;
		player->PlayerStatus[player->Level].Str += ItemList[4].ItemStatus.Str;
		player->PlayerStatus[player->Level].Def += ItemList[4].ItemStatus.Def;
		break;
	default:
		break;
	}
}

void ReturnFunctionItem(PLAYER* player, ITEM* ItemList, int itemnumber) {
	switch (itemnumber)
	{
	case 1:
		player->PlayerStatus[player->Level].HP -= ItemList[0].ItemStatus.HP;
		player->PlayerStatus[player->Level].Str -= ItemList[0].ItemStatus.Str;
		player->PlayerStatus[player->Level].Def -= ItemList[0].ItemStatus.Def;
		break;
	case 2:
		player->PlayerStatus[player->Level].HP -= ItemList[1].ItemStatus.HP;
		player->PlayerStatus[player->Level].Str -= ItemList[1].ItemStatus.Str;
		player->PlayerStatus[player->Level].Def -= ItemList[1].ItemStatus.Def;
		break;
	case 3:
		player->PlayerStatus[player->Level].HP -= ItemList[2].ItemStatus.HP;
		player->PlayerStatus[player->Level].Str -= ItemList[2].ItemStatus.Str;
		player->PlayerStatus[player->Level].Def -= ItemList[2].ItemStatus.Def;
		break;
	case 4:
		player->PlayerStatus[player->Level].HP -= ItemList[3].ItemStatus.HP;
		player->PlayerStatus[player->Level].Str -= ItemList[3].ItemStatus.Str;
		player->PlayerStatus[player->Level].Def -= ItemList[3].ItemStatus.Def;
		break;
	case 5:
		player->PlayerStatus[player->Level].HP -= ItemList[4].ItemStatus.HP;
		player->PlayerStatus[player->Level].Str -= ItemList[4].ItemStatus.Str;
		player->PlayerStatus[player->Level].Def -= ItemList[4].ItemStatus.Def;
		break;
	default:
		break;
	}
}