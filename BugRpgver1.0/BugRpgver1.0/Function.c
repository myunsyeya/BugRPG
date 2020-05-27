#include "Function.h"

void initialize(PLAYER* Player, PLAYER* PlayerLable, MONSTER* Monster, MONSTER* MonsterList,
	SKILL* SkillList, ITEM* ItemList, POS* PlayerPos, char Map[MAP_SIZE][MAP_SIZE])
{
	memset(Player, 0, sizeof(*Player));
	memset(PlayerLable, 0, sizeof(*PlayerLable));
	memset(Monster, 0, sizeof(Monster));
	memset(MonsterList, 0, sizeof(*MonsterList) * 10);
	memset(SkillList, 0, sizeof(*SkillList) * 10);
	memset(ItemList, 0, sizeof(*ItemList) * 10);
	MakeMap(Map);
	MakePlayerLable(PlayerLable);
	MakeMonsterList(MonsterList);
	MakeSkillList(SkillList);
	MakeItemList(ItemList);
	MakePlayerSkill(Player, SkillList, 0, 0);
	MakePlayerItem(Player, ItemList, 0, 0);
	Player->life = 1;
	PlayerPos->x = 31;
	PlayerPos->y = 56;
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

void battle_ground(PLAYER* player, PLAYER Lable, MONSTER monster, MONSTER* monsterList, ITEM* ItemList) {
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
	while (battle_status(player, Lable, &monster, &count, &skillnumber, &itemnumber, &i)) {
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
		if (i != 0) while (KI != 13);                                            //턴
	}
	ReturnFunctionItem(player, ItemList, item);
	player->SkillLimit = 0;
}

void store_ground(PLAYER* player, ITEM* ItemList, SKILL* skillList)
{
	while (1) {
		system("cls");
		printf("상점입니다~\n뭐 사시고 싶으신 거 있나요?\n\n");
		printf(" 1 . 아이템 \n 2 . 스킬북(현재 불가능) \n X . 퇴장\n");
		char ki = KI;
		if (ki == '1') buyItem(player, ItemList);
		if (ki == '2') {
			printf("아, 죄송합니다. 스킬북은 현재 입수중이에요..\n");
			KI;
		}
		if (ki == 27) while (menu(player));                                      //메뉴
		if (ki == 'x' || ki == 'X') break;
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