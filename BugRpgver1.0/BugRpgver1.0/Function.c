#include "Function.h"

void init()
{
	printf("메뉴는 ESC입니다.\n");
	printf("\n" "\n" "\n" "\n" "\n");
	printf("\t\t  #######      ##        ##       ######         ########     ########       ######\n");
	printf("\t\t  ##     ##    ##        ##      ##              ##     ##    ##     ##     ##    ##\n");
	printf("\t\t  ##     ##    ##        ##     ##               ##     ##    ##     ##    ##\n");
	printf("\t\t  #######      ##        ##    ##     #####      ########     ########    ##     #####\n");
	printf("\t\t  ##     ##    ##        ##     ##      ##       ##   ##      ##           ##      ##\n");
	printf("\t\t  ##     ##     ##      ##       ##    ##        ##    ##     ##            ##    ##\n");
	printf("\t\t  #######         ######          ######         ##     ##    ##             ######\n");
	printf("\n" "\n");
	printf("\t\t\t\t\t플레이 하시려면 ENTER키를 눌러주세요.\n");
	printf("\t\t\t\t\t      나가시려면 X를 눌러주세요.");
}

int back_graund(PLAYER* player, POS* playerpos, char map[MAP_SIZE][MAP_SIZE], int life) {
	system("cls");
	PrintMapByPlayer(map, *playerpos);
	switch (KI) {                                      //입력 스위치
	case 27:                                           //메뉴
		while (menu(player)); break;
	case 119:                                          //플레이어 이동 'w' 전
		if (map[playerpos->y - 1][playerpos->x] != '0')
			playerpos->y--;
		break;
	case 97:                                          //               'a' 좌
		if (map[playerpos->y][playerpos->x - 1] != '0')
			playerpos->x--;
		break;
	case 115:                                          //              's' 후
		if (map[playerpos->y + 1][playerpos->x] != '0')
			playerpos->y++;
		break;
	case 100:                                          //              'd' 우
		if (map[playerpos->y][playerpos->x + 1] != '0')
			playerpos->x++;
		break;
	case 120:									       // 전체 맵 확인 'x'
		system("cls");
		PrintMapTotal(map, *playerpos);
	default: break;
	}
	return life;
}

void battle_ground(PLAYER* player, PLAYER Lable, POS* playerpos, char map[MAP_SIZE][MAP_SIZE], MONSTER monster, MONSTER* list, ITEM* ItemList, int* life) {
	if (map[playerpos->y][playerpos->x] == '2' && rand() % 3 == 2) {
		MakeMonster(&monster, list, player->Level);
		printf("이런, %s가 나타났다.", monster.name);
		while (KI != 13);
		int count = 0;
		int constrant = 0;
		int skillnumber = 0;
		int itemnumber = 0;
		int skill = 0;
		int item = 0;
		int i = 0;
		while (battle_status(player, Lable, &monster, life, &count, &skillnumber, &itemnumber, &i)){
			if (*life == 2) {                                                       //승리 판정
				*life = 1;
				break;
			}
			if (skillnumber != 0) {                                                 //스킬 발동
				constrant = FunctionSkill(player, &monster, skillnumber, constrant);
				skill = skillnumber;
				skillnumber = 0;
			}
			if (constrant != 0) {                                                   //지속 스킬
				constrant--;
				FunctionSkill(player, &monster, skill, constrant);
			}
			if (itemnumber != 0) {
				FunctionItem(player, ItemList, itemnumber);
				item = itemnumber;
				itemnumber = 0;
			}
			if(i != 0) while (KI != 13);                                            //턴
		}
		ReturnFunctionItem(player, ItemList, item);
		player->SkillLimit = 0;
	}
}