#include "Function.h"

int main() {
	srand((unsigned int)time(NULL));
	char Map[MAP_SIZE][MAP_SIZE] = { 0 };
	int ki;
	int Life = 1;
	PLAYER Player;
	PLAYER PlayerLable;
	MONSTER MonsterList[10];
	MONSTER Monster;
	POS PlayerPos;
	PlayerPos.x = 25;
	PlayerPos.y = 5;
	memset(&Player, 0, sizeof(Player));
	memset(&PlayerLable, 0, sizeof(PlayerLable));
	memset(&MonsterList, 0, sizeof(MonsterList));
	memset(&Monster, 0, sizeof(Monster));
	MakeMap(Map);
	MakePlayerLable(&PlayerLable);
	MakeMonsterList(MonsterList);
	init();
	while (1)
	{
		ki = _getch();
		if (ki == 13)                     //Enter 시작
		{
			system("cls");
			MakePlayer(&Player, PlayerLable);
			while (back_graund(&Player, &PlayerPos, Map, Life)) {
				battle_ground(&Player, PlayerLable, &PlayerPos, Map, Monster, MonsterList, &Life);
				if (Life == 0) break;
			}
			break;
		}
		if (ki == 120 || ki == 88) break; //나가기
	}
	return 0;
}
