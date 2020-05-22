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
		if (KI)                     //Enter ����
		{
			system("cls");
			MakePlayer(Player, *PlayerLable);
			while (back_graund(Player, PlayerPos, Map)) {
				battle_ground(Player, *PlayerLable, PlayerPos, Map, *Monster, MonsterList, ItemList);
				if (Player->life == 0) break;
			}
			break;
		}
		if (KI == 120 || KI == 88) break; //������
	}
	system("cls");
	printf("���̹���~");
	Sleep(2000);
	freeAll(Player, PlayerLable, Monster, MonsterList, SkillList, ItemList, PlayerPos);
	return 0;
}
