#include "Function.h"

int main() {
	srand((unsigned int)time(NULL));
	char Map[MAP_SIZE][MAP_SIZE] = { 0 };
	PLAYER Player;
	PLAYER Lable;
	POS PlayerPos;
	PlayerPos.x = 25;
	PlayerPos.y = 5;
	memset(&Player, 0, sizeof(Player));
	memset(&Lable, 0, sizeof(Lable));
	MakeMap(Map);
	PlayerLable(&Lable);
	init();
	while (1)
	{
		if (KI == 13)                     //Enter ����
		{
			system("cls");
			MakePlayer(&Player, &Lable);
			back_graund(&Player, &PlayerPos, Map);
			break;
		}
		if (KI == 120 || KI == 88) break; //������
	}
	return 0;
}
