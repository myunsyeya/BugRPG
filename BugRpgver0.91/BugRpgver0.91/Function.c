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

int back_graund(PLAYER* player, POS* playerpos, char map[MAP_SIZE][MAP_SIZE]) {
	system("cls");
	PrintMapByPlayer(map, *playerpos);
	MoveMap(map, playerpos);
	switch (KI) {
	case 27:                                           //메뉴
		while (menu(player)); break;
	case 119:                                          //플레이어 이동 'w' 전
		if (map[playerpos->y - 1][playerpos->x] != '0')
			playerpos->y--;
		break;
	case 97:                                          //              'a' 좌
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
	if (player->PlayerStatus[player->Level].HP == 0) { //죽음
		system("cls");
		puts("사망하셨습니다. x를 눌러 조의를 표하십시오.");
		if (KI == 120 || KI == 88) return 0;
	}
	return back_graund(player, playerpos, map);
}
