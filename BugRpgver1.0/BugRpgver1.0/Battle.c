#include "Battle.h"
#include "Skill.h"

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
		for (; player->PlayerStatus[player->Level].Exp > player->PlayerStatus[player->Level].Max_Exp; exp = player->PlayerStatus[player->Level].Exp - player->PlayerStatus[player->Level].Max_Exp)
		{
			puts("\nLevel Up!");
			player->Level++;
			CheckStatus(player, Lable, player->Level);
			player->PlayerStatus->Exp = exp;
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
			if (KI == 114) {                                                     //'r'
				CheckStatus(player, Lable, player->Level);
				DiePlayer(player);
				return 2;
			}
			if (KI == 27) return 1;                                              //ESC
		}
		break;
	case 2: system("cls");
		puts("잡았다..");
		GiveExp(player, monster);
		LevelUP(player, Lable);
		while (KI != 13);
		return 2;
		break;
	}
	return 0;
}

int AttackSpd(PLAYER* player, PLAYER Lable, MONSTER* monster, int* life) {
	if (player->PlayerStatus[player->Level].Spd < monster->MonsterStatus.Spd) {
		puts("칫, 선공을 받았다.");
		MonsterHit(player, monster);
		printf("%s로부터 %d의 대미지!\n", monster->name, monster->MonsterStatus.Str);
		*life = CheckWinner(player, Lable, monster);
		switch (*life)
		{
		case 0: break;
		case 1: return 0;
		case 2: return 2;
		}
		PlayerHit(player, monster);
		printf("%s에게 %d의 대미지를 주었다.", monster->name, player->PlayerStatus[player->Level].Str);
		*life = CheckWinner(player, Lable, monster);
		switch (*life)
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
		*life = CheckWinner(player, Lable, monster);
		switch (*life)
		{
		case 0: break;
		case 1: return 0;
		case 2: return 2;
		}
		MonsterHit(player, monster);
		printf("%s로부터 %d의 대미지!", monster->name, monster->MonsterStatus.Str);
		*life = CheckWinner(player, Lable, monster);
		switch (*life)
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
	printf("%s :   ", monster->name);
	printf("Hp : %d|%d ", monster->MonsterStatus.HP, monster->MonsterStatus.Max_HP);
	printf("/Str : %d ", monster->MonsterStatus.Str);
	printf("/Def : %d ", monster->MonsterStatus.Def);
	printf("/Spd : %d\n\n", monster->MonsterStatus.Spd);
	printf("%s :   ", player->name);
	printf("Hp : %d|%d ", player->PlayerStatus[player->Level].HP, player->PlayerStatus[player->Level].Max_HP);
	printf("/San : %d|%d ", player->PlayerStatus[player->Level].San, player->PlayerStatus[player->Level].Max_San);
	printf("/Str : %d ", player->PlayerStatus[player->Level].Str);
	printf("/Def : %d ", player->PlayerStatus[player->Level].Def);
	printf("/Spd : %d\n\n", player->PlayerStatus[player->Level].Spd);
	printf(" 1 . 공격 \n 2 . 스킬 \n 3. 아이템 \n ESC . 도망");
}

int battle_status(PLAYER* player, PLAYER Lable, MONSTER* monster, int* life, int* count, int* skillnumber) {
	battlestatus(player, monster);
	int i = 0;
	switch (KI) {
	case 49: /*숫자1*/
		i = 1;
		system("cls");
		*life = AttackSpd(player, Lable, monster, life);
		break;
	case 50:/*숫자2*/
		BattleSkill(player, skillnumber);
		i = 1;
		break;
	case 51:/*숫자3*/
		i = 1;
		break;
	case 27:/*ESC키*/
		system("cls");
		return 0;
	}
	if (*life == 0 || *life == 2) i = 0;                                         /*사망판정*/
	if (i == 1) {                                                                /*턴 개념 Enter*/
		(*count)++;
		printf("\n\n%d turn", *count);
		while (KI != 13);
	}
	return *life;
}