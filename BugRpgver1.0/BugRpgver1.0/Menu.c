#include "Menu.h"

int menu(PLAYER* player) {
	int i = 0;
	system("cls");
	printf(" 1 . ������ \n 2 . ���� \n 3. ��ų \n ESC . ������");
	switch (KI) {
		case 49: /*����1*/
			system("cls");
			printf("ESC . ������");
			printf("\n");
			printf("\n ������\n\n");
			printf("\n ��� %d\n", player->PlayerStatus[player->Level].Gold);
			printf("\n");
			printf("\n");
			printf("item list : ");
			for (i = 0; player->inventory[i].itemnumber != 0; i++) {
				printf("%d.%s  :  \n\n", i + 1, player->inventory[i].name);
				printf("             %s", player->inventory[i].info);
			}
			while (1) if (KI == 27) break;
			break;
		case 50:/*����2*/
			system("cls");
			printf("ESC . ������");
			printf("\n");
			printf("\n %s�� ����\n\n", player->name);
			printf("\n �̸�: %s \n", player->name);
			printf("\n ���� %d \n", player->Level);
			printf("\n ����ġ/�ִ����ġ %d/%d \n", player->PlayerStatus[player->Level].Exp, player->PlayerStatus[player->Level].Max_Exp);
			printf("\n HP/�ִ�HP %d/%d \n", player->PlayerStatus[player->Level].HP, player->PlayerStatus[player->Level].Max_HP);
			printf("\n SP/�ִ�SP %d/%d \n", player->PlayerStatus[player->Level].San, player->PlayerStatus[player->Level].Max_San);
			printf("\n ���� %d \n", player->PlayerStatus[player->Level].Def);
			printf("\n �� %d \n", player->PlayerStatus[player->Level].Str);
			printf("\n �ӵ� %d \n", player->PlayerStatus[player->Level].Spd);
			printf("\n");
			while (1) if ((int)_getch() == 27) break;
			break;
		case 51:/*����3*/
			system("cls");
			printf("ESC . ������");
			printf("\n");
			printf("\n");
			printf("skill list : ");
			for (i = 0; player->PlayerSkill[i].SkillNumber != 0; i++) {
				printf("%d.%s  :  \n\n", i + 1, player->PlayerSkill[i].name);
				printf("             %s", player->PlayerSkill[i].Index);
			}
			while (1) if ((int)_getch() == 27) break;
			break;
		case 27:/*ESCŰ*/
			system("cls");
			return 0;
	}
	return 1;
}

//int back_graund(PLAYER* player) {
//	int  kl = 0;
//	kl = _getch();
//	if (kl == 27)
//	{
//		menu(player);
//	}
//	if (player->PlayerStatus[player->Level].HP == 0)
//	{
//		return 0;
//	}
//	else
//	{
//		return back_graund(player);
//	}
//}

//void menu(PLAYER* player) {
//	system("cls");
//	int kl;
//	int k = 1;
//	printf(" 1 . ������ \n 2 . ���� \n 3. ��ų \n ESC . ������");
//	while (k)
//	{
//
//		kl = _getch();
//		switch (kl)
//		{
//		case 49: /*����1*/
//			system("cls");
//			printf("\n");
//			printf("\n ������\n\n");
//			printf("\n ��� %d\n", player->PlayerStatus[player->Level].Gold);
//			printf("\n");
//			while (k)/*�޴��� ���ư��� �ҽ�*/
//			{
//				kl = _getch();
//				switch (kl)
//				{
//				case 27:
//					system("cls");
//					menu(player);
//				default:
//					break;
//				}
//			}
//			break;
//		case 50:/*����2*/
//			system("cls");
//			printf("\n");
//			printf("\n %s�� ����\n\n", player->name);
//			printf("\n �̸�: %s \n", player->name);
//			printf("\n ���� %d \n", player->Level);
//			printf("\n ����ġ/�ִ����ġ %d/%d \n", player->PlayerStatus[player->Level].Exp, player->PlayerStatus[player->Level].Max_Exp);
//			printf("\n HP/�ִ�HP %d/%d \n", player->PlayerStatus[player->Level].HP, player->PlayerStatus[player->Level].Max_HP);
//			printf("\n SP/�ִ�SP %d/%d \n", player->PlayerStatus[player->Level].San, player->PlayerStatus[player->Level].Max_San);
//			printf("\n ���� %d \n", player->PlayerStatus[player->Level].Def);
//			printf("\n �� %d \n", player->PlayerStatus[player->Level].Str);
//			printf("\n �ӵ� %d \n", player->PlayerStatus[player->Level].Spd);
//			printf("\n");
//			while (k)/*�޴��� ���ư��� �ҽ�*/
//			{
//				kl = _getch();
//				switch (kl)
//				{
//				case 27:
//					system("cls");
//					menu(player);
//				default:
//					break;
//				}
//			}
//			break;
//		case 51:/*����3*/
//			system("cls");
//			printf("\n");
//			printf("\n ��ų\n");
//			printf("\n");
//			while (k)/*�޴��� ���ư��� �ҽ�*/
//			{
//				kl = _getch();
//				switch (kl)
//				{
//				case 27:
//					system("cls");
//					menu(player);
//				default:
//					break;
//				}
//			}
//			break;
//		case 27:/*ESCŰ*/
//			system("cls");
//			k = 0;
//		default:
//			break;
//		}
//	}
//}
