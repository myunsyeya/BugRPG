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

int back_graund(PLAYER* player, POS* playerpos, char map[MAP_SIZE][MAP_SIZE], int life) {
	system("cls");
	PrintMapByPlayer(map, *playerpos);
	switch (KI) {                                      //�Է� ����ġ
	case 27:                                           //�޴�
		while (menu(player)); break;
	case 119:                                          //�÷��̾� �̵� 'w' ��
		if (map[playerpos->y - 1][playerpos->x] != '0')
			playerpos->y--;
		break;
	case 97:                                          //               'a' ��
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
	return life;
}

void battle_ground(PLAYER* player, PLAYER Lable, POS* playerpos, char map[MAP_SIZE][MAP_SIZE], MONSTER monster, MONSTER* list, int* life) {
	if (map[playerpos->y][playerpos->x] == '2' && rand() % 50 == 2) {
		MakeMonster(&monster, list, player->Level);
		printf("�̷�, %s�� ��Ÿ����.", monster.name);
		while (KI != 13);
		int count = 0;
		int constrant = 0;
		int skillnumber = 0;
		int skill = 0;
		int i = 0;
		while (battle_status(player, Lable, &monster, life, &count, &skillnumber, &i)){
			if (*life == 2) {
				*life = 1;
				break;
			}
			if (skillnumber != 0) {
				constrant = FunctionSkill(player, &monster, skillnumber, constrant);
				skill = skillnumber;
				skillnumber = 0;
			}
			if (constrant != 0) {
				constrant--;
				FunctionSkill(player, &monster, skill, constrant);
			}
			if(i != 0) while (KI != 13);
		}
		player->SkillLimit = 0;
	}
}