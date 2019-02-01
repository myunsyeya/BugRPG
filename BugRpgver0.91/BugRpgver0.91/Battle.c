#include "Battle.h"

void PlayerHitBySkill(PLAYER* player, MONSTER* monster)
{
	switch (KI)
	{
	case 1:
		monster->MonsterStatus.HP -= player->PlayerStatus[player->Level].Str * player->PlayerSkill[0].Data;
		break;
	case 2:
		monster->MonsterStatus.HP -= player->PlayerStatus[player->Level].Str * player->PlayerSkill[0].Data;
		break;
	default:
		PlayerHit(player,monster);
		break;
	}
}

void PlayerHitByStr(PLAYER* player, MONSTER* monster)
{
	monster->MonsterStatus.HP = player->PlayerStatus[player->Level].Str;
}

void PlayerHit(PLAYER * player, MONSTER * monster)
{
	switch (KI)
	{
	case 1:
		PlayerHitByStr(player, monster);
		break;
	case 2:
		PlayerHitBySkill(player, monster);
		break;
	default:
		break;
	}
}

void MonsterHit(PLAYER * player, MONSTER * monster)
{
	if (player->PlayerStatus[player->Level].San > 0)
	{
		player->PlayerStatus[player->Level].San -= monster->MonsterStatus.Str;
	}
	else
	{
		player->PlayerStatus[player->Level].HP -= monster->MonsterStatus.Str;
	}
	
}

int CheckHP(PLAYER* player, MONSTER* monster)
{
	if (player->PlayerStatus[player->Level].HP <= 0)
		return 1;
	else if (monster->MonsterStatus.HP <= 0)
		return 2;
	return 0;
}

void GiveExp(PLAYER* player, int exp)
{
	player->PlayerStatus[player->Level].Exp += exp;
	
}

void DieExp(PLAYER* player)
{
	player->PlayerStatus[player->Level].Exp = 0;
}

void LeveLUP(PLAYER* player)
{
	if (player->PlayerStatus[player->Level].Exp > player->PlayerStatus[player->Level].Max_Exp)
	{
		for (int i = 0; player->PlayerStatus[player->Level].Exp < player->PlayerStatus[player->Level].Max_Exp; i++)
		{
			player->Level++;
			player->PlayerStatus[player->Level].Exp -= player->PlayerStatus[player->Level].Max_Exp;
			
			if (player->Level % 4 == 0)
			{
				int i = rand() % 5;
					switch (i) {
					case 0: player->PlayerStatus[player->Level].Str += 3; puts("랜덤적으로 힘이 3 증가했습니다.\n"); break;
					case 1: player->PlayerStatus[player->Level].Def += 3; puts("랜덤적으로 방어력이 3 증가했습니다.\n"); break;
					case 2: player->PlayerStatus[player->Level].Max_HP += 5; puts("랜덤적으로 최대체력이 5 증가했습니다.\n"); break;
					case 3: player->PlayerStatus[player->Level].Spd += 6; puts("랜덤적으로 스피드가 6 증가했습니다..\n"); break;
					case 4: player->PlayerStatus[player->Level].Max_San += 10; puts("랜덤적으로 최대정신력이 10 증가했습니다.\n"); break;
				}
			}
		}
		
	}
}



void BattlebyCheckSpd(PLAYER * player, MONSTER * monster)
{
	int Check;
	if (player->PlayerStatus[player->Level].Spd > monster->MonsterStatus.Spd)
	{
		while (1)
		{
			PlayerHit(player, monster);
			if (Check = CheckHP(player,monster))
				break;
			MonsterHit(player, monster);
			if (Check = CheckHP(player,monster))
				break;
		}
		if (Check == 2)
		{
			GiveExp(player, monster->MonsterStatus.Exp);
		}
			
	}
	else
	{
		while (1)
		{
			MonsterHit(player, monster);
			if (Check = CheckHP(player, monster))
				break;
			PlayerHit(player, monster);
			if (Check = CheckHP(player, monster))
				break;
		}
		if (Check == 1)
		{
			DieExp(player);
		}
	}
}
