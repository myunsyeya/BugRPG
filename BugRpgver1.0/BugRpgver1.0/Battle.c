#include "Battle.h"
/*최신*/

void statusBarHp(PLAYER *player)
{
	int t;
	int hp = (int)player->PlayerStatus[player->Level].HP;
	int maxHp = (int)player->PlayerStatus[player->Level].Max_HP;
	t = maxHp / 10;
	for (int c = 0; c != 10; c++)
	{
		if (hp >= t)
		{
			printf("■");
		}
		else
		{
			printf("□");
		}
		hp = hp - t;
	}
}

void statusBarSan(PLAYER *player)
{
	int t;
	int san = (int)player->PlayerStatus[player->Level].San;
	int maxSan = (int)player->PlayerStatus[player->Level].Max_San;
	t = maxSan / 10;
	for (int c = 0; c != 10; c++)
	{
		if (san >= t)
		{
			printf("■");
		}
		else
		{
			printf("□");
		}
		san = san - t;
	}
}

void monsterHpBar(MONSTER *monster)
{
	int t;
	int hp = (int)monster->MonsterStatus.HP;
	int maxHp = (int)monster->MonsterStatus.Max_HP;
;
	t = maxHp / 10;
	for (int c = 0; c != 10; c++)
	{
		if (hp >= t)
		{
			printf("■");
		}
		else
		{
			printf("□");
		}
		hp = hp - t;
	}
}

void PlayerHit(PLAYER* player, MONSTER* monster)                               //일반공격
{
	monster->MonsterStatus.HP -= player->PlayerStatus[player->Level].Str;
}

void MonsterHit(PLAYER * player, MONSTER * monster)                            //몬스터 일반공격
{
	if (player->PlayerStatus[player->Level].San > monster->MonsterStatus.Str) 
		player->PlayerStatus[player->Level].San -= monster->MonsterStatus.Str;
	else if(player->PlayerStatus[player->Level].San == 0) 
		player->PlayerStatus[player->Level].HP -= monster->MonsterStatus.Str;
	else
	{
		player->PlayerStatus[player->Level].HP -= monster->MonsterStatus.Str - player->PlayerStatus[player->Level].San;
		player->PlayerStatus[player->Level].San = 0;
	}
	
}

int CheckHP(PLAYER* player, MONSTER* monster)                                   //몬스터가 죽었는지 플레이어가 죽었는지 체크
{
	if (player->PlayerStatus[player->Level].HP <= 0)
		return 1;
	else if (monster->MonsterStatus.HP <= 0)
		return 2;
	return 0;
}

void GiveExp(PLAYER* player, MONSTER* monster)                                  //경험치 획득
{
	player->PlayerStatus[player->Level].Exp += monster->MonsterStatus.Exp;
}

void GiveGold(PLAYER* player, MONSTER* monster) {                               //골드 획득
	player->PlayerStatus[player->Level].Gold += monster->MonsterStatus.Gold;
}

void DiePlayer(PLAYER* player)                                                  //죽을 시 경험치
{
	player->PlayerStatus[player->Level].Exp = 0;
	player->PlayerStatus[player->Level].HP = player->PlayerStatus[player->Level].Max_HP;
	player->PlayerStatus[player->Level].San = player->PlayerStatus[player->Level].Max_San;
}

void LevelUP(PLAYER* player, PLAYER Lable)                                       //레벨업 프렌드
{
	if (player->PlayerStatus[player->Level].Exp > player->PlayerStatus[player->Level].Max_Exp)
	{
		int exp = 0;
		int gold = 0;
		for (exp = player->PlayerStatus[player->Level].Exp - player->PlayerStatus[player->Level].Max_Exp; player->PlayerStatus[player->Level].Exp > player->PlayerStatus[player->Level].Max_Exp; exp = player->PlayerStatus[player->Level].Exp - player->PlayerStatus[player->Level].Max_Exp)
		{
			gold = player->PlayerStatus[player->Level].Gold;
			puts("\nLevel Up!");
			player->Level++;
			CheckStatus(player, Lable, player->Level);
			player->PlayerStatus[player->Level].Exp = exp;
			player->PlayerStatus[player->Level].Gold = gold;
			if (player->Level % 4 == 0)
			{
				int i = rand() % 5;
					switch (i) {
					case 0: player->addStatus.Str += 3; puts("랜덤적으로 힘이 3 증가했습니다.\n"); break;
					case 1: player->addStatus.Def += 3; puts("랜덤적으로 방어력이 3 증가했습니다.\n"); break;
					case 2: player->addStatus.Max_HP += 5; puts("랜덤적으로 최대체력이 5 증가했습니다.\n"); break;
					case 3: player->addStatus.Spd += 6; puts("랜덤적으로 스피드가 6 증가했습니다..\n"); break;
					case 4: player->addStatus.Max_San += 10; puts("랜덤적으로 최대정신력이 10 증가했습니다.\n"); break;
				}
			}
			CheckAddStatus(player);
		}
		
	}
}

int CheckWinner(PLAYER* player, PLAYER Lable, MONSTER* monster) {
	switch (CheckHP(player, monster))
	{
	case 0: return 0; break;
	case 1: system("cls");
		puts("사망하셨습니다. x를 눌러 조의를 표하십시오.");
		while (KI != 120);                                                       //'x'
		system("cls");
		puts(" R . 부활 \n ESC . 나가기");
		while (1) {
			char ki = KI;
			if (ki == 114) {                                                     //'r'
				CheckStatus(player, Lable, player->Level);
				DiePlayer(player);
				return 2;
			}
			if (ki == 27) return 1;                                              //ESC
		}
		break;
	case 2: system("cls");
		puts("잡았다..");
		GiveExp(player, monster);
		printf("\n%d의 경험치를 얻었다!", monster->MonsterStatus.Exp);
		GiveGold(player, monster);
		printf("\n%d의 금화를 얻었다!", monster->MonsterStatus.Gold);
		printf("\n\n'벌레가 어떻게 금화를 가지고 있지..?'");
		LevelUP(player, Lable);
		while (KI != 13);
		return 2;
		break;
	}
	return 0;
}

int AttackSpd(PLAYER* player, PLAYER Lable, MONSTER* monster) {
	if (player->PlayerStatus[player->Level].Spd < monster->MonsterStatus.Spd) {
		puts("칫, 선공을 받았다.");
		MonsterHit(player, monster);
		printf("%s로부터 %d의 대미지!\n", monster->name, monster->MonsterStatus.Str);
		player->life = CheckWinner(player, Lable, monster);
		switch (player->life)
		{
		case 0: break;
		case 1: return 0;
		case 2: return 2;
		}
		PlayerHit(player, monster);
		printf("%s에게 %d의 대미지를 주었다.", monster->name, player->PlayerStatus[player->Level].Str);
		player->life = CheckWinner(player, Lable, monster);
		switch (player->life)
		{
		case 0: break;
		case 1: return 0;
		case 2: return 2;
		}
	}
	else {
		puts("캇.. 벌레녀석 이정도 밖에 안되나.");
		PlayerHit(player, monster);
		printf("%s에게 %d의 대미지를 주었다.\n", monster->name, player->PlayerStatus[player->Level].Str);
		player->life = CheckWinner(player, Lable, monster);
		switch (player->life)
		{
		case 0: break;
		case 1: return 0;
		case 2: return 2;
		}
		MonsterHit(player, monster);
		printf("%s로부터 %d의 대미지!", monster->name, monster->MonsterStatus.Str);
		player->life = CheckWinner(player, Lable, monster);
		switch (player->life)
		{
		case 0: break;
		case 1: return 0;
		case 2: return 2;
		}
	}
	return 1;
}

void battlestatus(PLAYER* player, MONSTER* monster) {
	system("cls");
	printf("\n");
	printf("  %s \n", monster->name);
	printf(" ┌────────────────────────────────┐\n");
	printf(" │몬스터 HP : ");
	monsterHpBar(monster);
	printf("│\n");
	printf(" └────────────────────────────────┘\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("  %s \n", player->name);
	printf(" ┌───────────────────────────┐\n"); 
	printf(" │  HP : ");
	statusBarHp(player);
	printf("│");
	printf("\n │ SAN : ");
	statusBarSan(player);
	printf("│");
	printf("\n");
	printf(" ├───────────────────────────┴────────┐");
	printf("\n │ 1.공격  2.스킬  3.아이템  ESC.도망 │\n");
	printf(" └────────────────────────────────────┘");
	printf("\n");
}

int battle_status(PLAYER* player, PLAYER Lable, MONSTER* monster, int* count, 
	int* skillnumber, int* itemnumber, int* i) {
	battlestatus(player, monster);
	*i = 0;
	switch (KI) {
	case 49: /*숫자1*/
		*i = 1;
		system("cls");
		player->life = AttackSpd(player, Lable, monster);
		break;
	case 50:/*숫자2*/
		BattleSkill(player, skillnumber);
		*i = 1;
		break;
	case 51:/*숫자3*/
		BattleItem(player, itemnumber);
		*i = 1;
		break;
	case 27:/*ESC키*/
		system("cls");
		return 0;
	}
	if (player->life == 0 || player->life == 2) *i = 0;                                 /*사망판정*/
	return player->life;
}