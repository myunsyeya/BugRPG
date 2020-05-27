#include "store.h"

void buyItem(PLAYER* player, ITEM* ItemList)
{
	system("cls");
	printf("현재 판매하고 있는 아이템은 아래와 같습니다!\n\n");
	Sleep(1000);
	for (int i = 0; i < ITEMSIZE; i++) {
		printf("%d . %s\n", i + 1, ItemList[i].name);
		printf("%s\n", ItemList[i].info);
		printf("가격 : %d Gold\n\n", ItemList[i].ItemStatus.Gold);
	}
	printf("구입하고 싶은 아이템의 번호를 적어주세요!\n");
	printf("혹 마음이 바뀌셨으면 X를 눌러주세요.\n");
	printf("입력모드로의 전환은 Enter키를 눌러주시면 되요!\n");
	while (1) {
	char ki = KI;
	int itemnumber;
	if (ki == 13) {
		do {
			printf("구입 : ");
			scanf_s("%d", &itemnumber);
			if (itemnumber < 0 || itemnumber > ITEMSIZE + 1) {
				printf("당부드리는 거지만, 위의 번호와 맞게 입력해주셔야 해요.\n");
				KI;
				system("cls");
			}
		} while (itemnumber < 0 || itemnumber > ITEMSIZE + 1);
		fflush(stdin);
		if (player->PlayerStatus->Gold >= ItemList[itemnumber - 1].ItemStatus.Gold) {
			player->PlayerStatus->Gold -= ItemList[itemnumber - 1].ItemStatus.Gold;
			player->inventory[itemnumber - 1] = ItemList[itemnumber - 1];
			printf("결제되었습니다!\n");
			KI;
		}
		else {
			printf("돈이.. 부족하신 것 같아요.\n");
			printf("아마.. %d 쯤?", ItemList[itemnumber - 1].ItemStatus.Gold - player->PlayerStatus->Gold);
			KI;
		}
		break;
	}
	if (ki == 'x' || ki == 'X') break;
	}
}
