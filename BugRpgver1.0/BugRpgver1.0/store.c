#include "store.h"

void buyItem(PLAYER* player, ITEM* ItemList)
{
	system("cls");
	printf("���� �Ǹ��ϰ� �ִ� �������� �Ʒ��� �����ϴ�!\n\n");
	Sleep(1000);
	for (int i = 0; i < ITEMSIZE; i++) {
		printf("%d . %s\n", i + 1, ItemList[i].name);
		printf("%s\n", ItemList[i].info);
		printf("���� : %d Gold\n\n", ItemList[i].ItemStatus.Gold);
	}
	printf("�����ϰ� ���� �������� ��ȣ�� �����ּ���!\n");
	printf("Ȥ ������ �ٲ������ X�� �����ּ���.\n");
	printf("�Է¸����� ��ȯ�� EnterŰ�� �����ֽø� �ǿ�!\n");
	while (1) {
	char ki = KI;
	int itemnumber;
	if (ki == 13) {
		do {
			printf("���� : ");
			scanf_s("%d", &itemnumber);
			if (itemnumber < 0 || itemnumber > ITEMSIZE + 1) {
				printf("��ε帮�� ������, ���� ��ȣ�� �°� �Է����ּž� �ؿ�.\n");
				KI;
				system("cls");
			}
		} while (itemnumber < 0 || itemnumber > ITEMSIZE + 1);
		fflush(stdin);
		if (player->PlayerStatus->Gold >= ItemList[itemnumber - 1].ItemStatus.Gold) {
			player->PlayerStatus->Gold -= ItemList[itemnumber - 1].ItemStatus.Gold;
			player->inventory[itemnumber - 1] = ItemList[itemnumber - 1];
			printf("�����Ǿ����ϴ�!\n");
			KI;
		}
		else {
			printf("����.. �����Ͻ� �� ���ƿ�.\n");
			printf("�Ƹ�.. %d ��?", ItemList[itemnumber - 1].ItemStatus.Gold - player->PlayerStatus->Gold);
			KI;
		}
		break;
	}
	if (ki == 'x' || ki == 'X') break;
	}
}
