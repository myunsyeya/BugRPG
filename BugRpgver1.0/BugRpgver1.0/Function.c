#include "Function.h"

void initialize(PLAYER* Player, PLAYER* PlayerLable, MONSTER* Monster, MONSTER* MonsterList,
	SKILL* SkillList, ITEM* ItemList, POS* PlayerPos, char Map[MAP_SIZE][MAP_SIZE])
{
	Player->life = 1;
	PlayerPos->x = 31;
	PlayerPos->y = 56;
	memset(Player, 0, sizeof(Player));
	memset(PlayerLable, 0, sizeof(PlayerLable));
	memset(MonsterList, 0, sizeof(MonsterList));
	memset(Monster, 0, sizeof(Monster));
	memset(SkillList, 0, sizeof(SkillList));
	memset(ItemList, 0, sizeof(ItemList));
	MakeMap(Map);
	MakePlayerLable(PlayerLable);
	MakeMonsterList(MonsterList);
	MakeSkillList(SkillList);
	MakeItemList(ItemList);
	MakePlayerSkill(Player, SkillList, 0, 0);
	MakePlayerItem(Player, ItemList, 0, 0);
}

void init()
{
	printf("메뉴는 ESC입니다.\n");
	printf("\n" "\n" "\n" "\n" "\n");
	printf("\t\t  #######      ##        ##       ######         ########     ########       ######\n");
	printf("\t\t  ##     ##    ##        ##      ##              ##     ##    ##     ##     ##    ##\n");
	printf("\t\t  ##     ##    ##        ##     ##               ##     ##    ##     ##    ##\n");
	printf("\t\t  #######      ##        ##    ##     #####      ########     ########    ##     #####\n");
	printf("\t\t  ##     ##    ##        ##     ##      ##       ##   ##      ##           ##      ##\n");
	printf("\t\t  ##     ##     ##      ##       ##    ##        ##    ##     ##            ##    ##\n");
	printf("\t\t  #######         ######          ######         ##     ##    ##             ######\n");
	printf("\n" "\n");
	printf("\t\t\t\t\t플레이 하시려면 ENTER키를 눌러주세요.\n");
	printf("\t\t\t\t\t      나가시려면 X를 눌러주세요.");
}

int back_graund(PLAYER* player, POS* playerPos, char map[MAP_SIZE][MAP_SIZE]) {
	static char input;
	system("cls");
	PrintMapByPlayer(map, *playerPos);
	Sleep(15);
	input = KI;
	if (input == 27) while (menu(player));                //메뉴
	MoveMap(map, playerPos, input);
	return player->life;
}

void battle_ground(PLAYER* player, PLAYER Lable, POS* playerPos, char map[MAP_SIZE][MAP_SIZE], 
	MONSTER monster, MONSTER* monsterList, ITEM* ItemList) {
	if (map[playerPos->y][playerPos->x] == '2' && rand() % 3 == 2) {
		MakeMonster(&monster, monsterList, player->Level);
		printf("이런, %s가 나타났다.", monster.name);
		while (KI != 13);
		int count = 0;
		int constrant = 0;
		int skillnumber = 0;
		int itemnumber = 0;
		int skill = 0;
		int item = 0;
		int i = 0;
		while (battle_status(player, Lable, &monster, &count, &skillnumber, &itemnumber, &i)){
			if (player->life == 2) {                                                //승리 판정
				player->life = 1;
				break;
			}
			if (skillnumber != 0) {                                                 //스킬 발동
				constrant = FunctionSkill(player, &monster, skillnumber, constrant);
				skill = skillnumber;
				skillnumber = 0;
			}
			if (constrant != 0) {                                                   //지속 스킬
				constrant--;
				FunctionSkill(player, &monster, skill, constrant);
			}
			if (itemnumber != 0) {
				FunctionItem(player, ItemList, itemnumber);
				item = itemnumber;
				itemnumber = 0;
			}
			if(i != 0) while (KI != 13);                                            //턴
		}
		ReturnFunctionItem(player, ItemList, item);
		player->SkillLimit = 0;
	}
}

void freeAll(PLAYER* Player, PLAYER* PlayerLable, MONSTER* Monster, MONSTER* MonsterList,
	SKILL* SkillList, ITEM* ItemList, POS* PlayerPos)
{
	free(Player);
	free(PlayerLable);
	free(Monster);
	free(MonsterList);
	free(SkillList);
	free(ItemList);
	free(PlayerPos);
}