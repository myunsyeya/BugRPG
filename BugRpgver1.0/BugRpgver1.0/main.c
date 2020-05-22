#include "Function.h"

int main() {
	srand((unsigned int)time(NULL));
	char Map[MAP_SIZE][MAP_SIZE] = { 0 };
	PLAYER* Player = malloc(sizeof(PLAYER));
	PLAYER* PlayerLable = malloc(sizeof(PLAYER));
	MONSTER* Monster = malloc(sizeof(MONSTER));
	MONSTER* MonsterList = malloc(sizeof(MONSTER) * 10);
	SKILL* SkillList = malloc(sizeof(SKILL) * 10);
	ITEM* ItemList = malloc(sizeof(ITEM) * 10);
	POS* PlayerPos = malloc(sizeof(POS));
	initialize(Player, PlayerLable, Monster, MonsterList, SkillList, ItemList, PlayerPos, Map);
	init();
	while (1)
	{
		char input = KI;
		if (input == 13)                     //Enter 시작
		{
			system("cls");
			MakePlayer(Player, *PlayerLable);
			while (back_graund(Player, PlayerPos, Map)) {
				battle_ground(Player, *PlayerLable, PlayerPos, Map, *Monster, MonsterList, ItemList);
				if (Player->life == 0) break;
			}
			break;
		}
		else if (input == 120 || input == 88) break; //나가기
	}
	system("cls");
	printf("바이바이~");
	Sleep(2000);
	getchar();
	freeAll(Player, PlayerLable, Monster, MonsterList, SkillList, ItemList, PlayerPos);
	return 0;
}
