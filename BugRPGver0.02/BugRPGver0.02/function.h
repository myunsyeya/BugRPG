#pragma once
#include "Common.h"
#include "Menu.h"
#include "Monster.h"
#include "Player.h"
#include "SKill.h"
#include "Item.h"

/*int back_graund(PLAYER* player);*/

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

void init()
{
	printf("메뉴는 ESC입니다.\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t  #######      ##        ##       ######         ########     ########       ######\n"		);
	printf("\t\t  ##     ##    ##        ##      ##              ##     ##    ##     ##     ##    ##\n"		);
	printf("\t\t  ##     ##    ##        ##     ##               ##     ##    ##     ##    ##\n"			);
	printf("\t\t  #######      ##        ##    ##     #####      ########     ########    ##     #####\n"	);
	printf("\t\t  ##     ##    ##        ##     ##      ##       ##   ##      ##           ##      ##\n"	);
	printf("\t\t  ##     ##     ##      ##       ##    ##        ##    ##     ##            ##    ##\n"		);
	printf("\t\t  #######         ######          ######         ##     ##    ##             ######\n"		);
	printf("\n");
	printf("\n");
	printf("\t\t\t\t\t플레이 하시려면 ENTER키를 눌러주세요.\n");
	printf("\t\t\t\t\t      나가시려면 X를 눌러주세요.");
}