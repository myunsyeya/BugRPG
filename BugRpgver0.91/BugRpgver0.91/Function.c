#include "Function.h"

void init()
{
	printf("�޴��� ESC�Դϴ�.\n");
	printf("\n" "\n" "\n" "\n" "\n");
	printf("\t\t  #######      ##        ##       ######         ########     ########       ######\n");
	printf("\t\t  ##     ##    ##        ##      ##              ##     ##    ##     ##     ##    ##\n");
	printf("\t\t  ##     ##    ##        ##     ##               ##     ##    ##     ##    ##\n");
	printf("\t\t  #######      ##        ##    ##     #####      ########     ########    ##     #####\n");
	printf("\t\t  ##     ##    ##        ##     ##      ##       ##   ##      ##           ##      ##\n");
	printf("\t\t  ##     ##     ##      ##       ##    ##        ##    ##     ##            ##    ##\n");
	printf("\t\t  #######         ######          ######         ##     ##    ##             ######\n");
	printf("\n" "\n");
	printf("\t\t\t\t\t�÷��� �Ͻ÷��� ENTERŰ�� �����ּ���.\n");
	printf("\t\t\t\t\t      �����÷��� X�� �����ּ���.");
}

int back_graund(PLAYER* player, POS* playerpos, char map[MAP_SIZE][MAP_SIZE]) {
	system("cls");
	PrintMapByPlayer(map, *playerpos);
	MoveMap(map, playerpos);
	switch (KI) {
	case 27:                                           //�޴�
		while (menu(player)); break;
	case 119:                                          //�÷��̾� �̵� 'w' ��
		if (map[playerpos->y - 1][playerpos->x] != '0')
			playerpos->y--;
		break;
	case 97:                                          //              'a' ��
		if (map[playerpos->y][playerpos->x - 1] != '0')
			playerpos->x--;
		break;
	case 115:                                          //              's' ��
		if (map[playerpos->y + 1][playerpos->x] != '0')
			playerpos->y++;
		break;
	case 100:                                          //              'd' ��
		if (map[playerpos->y][playerpos->x + 1] != '0')
			playerpos->x++;
		break;
	case 120:									       // ��ü �� Ȯ�� 'x'
		system("cls");
		PrintMapTotal(map, *playerpos);
	default: break;
	}
	if (player->PlayerStatus[player->Level].HP == 0) { //����
		system("cls");
		puts("����ϼ̽��ϴ�. x�� ���� ���Ǹ� ǥ�Ͻʽÿ�.");
		if (KI == 120 || KI == 88) return 0;
	}
	return back_graund(player, playerpos, map);
}
