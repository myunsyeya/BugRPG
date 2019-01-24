#pragma once
#include "Common.h"

int back_graund(PLAYER* player);
void menu(PLAYER* player); 

int back_graund(PLAYER* player) {
	int  kl = 0;
	kl = _getch();
	if (kl == 27)
	{
		menu(player);
	}
	if (player->PlayerStatus[player->Level].HP == 0)
	{
		return 0;
	}
	else
	{
		return back_graund(player);
	}
}

void menu(PLAYER* player) {
	system("cls");
	int kl;
	int k = 1;
	printf(" 1 . 아이템 \n 2 . 스탯 \n 3. 스킬 \n 4. 상점 \n ESC . 나가기");
	while (k)
	{

		kl = _getch();
		system("cls");
		switch (kl)
		{
		case 49: /*숫자1*/
			printf("\n");
			printf("\n 아이템\n\n");
			printf("\n 골드 %d\n", player->PlayerStatus[player->Level].Gold);
			printf("\n");
			while (k)/*메뉴로 돌아가는 소스*/
			{
				kl = _getch();
				switch (kl)
				{
				case 27:
					system("cls");
					menu(player);
				default:
					break;
				}
			}
			break;
		case 50:/*숫자2*/
			printf("\n");
			printf("\n %s의 스텟\n\n", player->name);
			printf("\n 이름: %s \n", player->name);
			printf("\n 레벨 %d \n", player->Level);
			printf("\n 경험치/최대경험치 %d/%d \n", player->PlayerStatus[player->Level].Exp, player->PlayerStatus[player->Level].Max_Exp);
			printf("\n HP/최대HP %d/%d \n", player->PlayerStatus[player->Level].HP, player->PlayerStatus[player->Level].Max_HP);
			printf("\n SP/최대SP %d/%d \n", player->PlayerStatus[player->Level].San, player->PlayerStatus[player->Level].Max_San);
			printf("\n 방어력 %d \n", player->PlayerStatus[player->Level].Def);
			printf("\n 힘 %d \n", player->PlayerStatus[player->Level].Str);
			printf("\n 속도 %d \n", player->PlayerStatus[player->Level].Spd);
			printf("\n");
			while (k)/*메뉴로 돌아가는 소스*/
			{
				kl = _getch();
				switch (kl)
				{
				case 27:
					system("cls");
					menu(player);
				default:
					break;
				}
			}
			break;
		case 51:/*숫자3*/
			printf("\n");
			printf("\n 스킬\n");
			printf("\n");
			while (k)/*메뉴로 돌아가는 소스*/
			{
				kl = _getch();
				switch (kl)
				{
				case 27:
					system("cls");
					menu(player);
				default:
					break;
				}
			}
			break;
		case 52:/*숫자4*/
			printf("\n");
			printf("\n 상점\n");
			printf("\n");
			while (k)/*메뉴로 돌아가는 소스*/
			{
				kl = _getch();
				switch (kl)
				{
				case 27:
					system("cls");
					menu(player);
				default:
					break;
				}
			}
			break;
		case 27:/*ESC키*/
			system("cls");
			k = 0;
		default:
			break;
		}
	}
}
