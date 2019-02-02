#include "Battle.h"

void PlayerHit(PLAYER* player, MONSTER* monster)                               //�Ϲݰ���
{
	monster->MonsterStatus.HP -= player->PlayerStatus[player->Level].Str;
}

void MonsterHit(PLAYER * player, MONSTER * monster)                            //���� �Ϲݰ���
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

int CheckHP(PLAYER* player, MONSTER* monster)                                   //���Ͱ� �׾����� �÷��̾ �׾����� üũ
{
	if (player->PlayerStatus[player->Level].HP <= 0)
		return 1;
	else if (monster->MonsterStatus.HP <= 0)
		return 2;
	return 0;
}

void GiveExp(PLAYER* player, MONSTER* monster)                                  //����ġ ȹ��
{
	player->PlayerStatus[player->Level].Exp += monster->MonsterStatus.Exp;
}

void DiePlayer(PLAYER* player)                                                  //���� �� ����ġ
{
	player->PlayerStatus[player->Level].Exp = 0;
	player->PlayerStatus[player->Level].HP = player->PlayerStatus[player->Level].Max_HP;
	player->PlayerStatus[player->Level].San = player->PlayerStatus[player->Level].Max_San;
}

void LevelUP(PLAYER* player, PLAYER Lable)                                       //������ ������
{
	PLAYER Addstatus;
	memset(&Addstatus, 0, sizeof(Addstatus));
	if (player->PlayerStatus[player->Level].Exp > player->PlayerStatus[player->Level].Max_Exp)
	{
		system("cls");
		AddStatusSave(player, &Addstatus, Lable);
		AddStatusApply(player, &Addstatus);
		for (int i = 0; player->PlayerStatus[player->Level].Exp < player->PlayerStatus[player->Level].Max_Exp; i++)
		{
			puts("Level Up!");
			player->Level++;
			player->PlayerStatus[player->Level].Exp -= player->PlayerStatus[player->Level].Max_Exp;	
			CheckStatus(player, Lable);
			if (player->Level % 4 == 0)
			{
				int i = rand() % 5;
					switch (i) {
					case 0: player->PlayerStatus[player->Level].Str += 3; puts("���������� ���� 3 �����߽��ϴ�.\n"); break;
					case 1: player->PlayerStatus[player->Level].Def += 3; puts("���������� ������ 3 �����߽��ϴ�.\n"); break;
					case 2: player->PlayerStatus[player->Level].Max_HP += 5; puts("���������� �ִ�ü���� 5 �����߽��ϴ�.\n"); break;
					case 3: player->PlayerStatus[player->Level].Spd += 6; puts("���������� ���ǵ尡 6 �����߽��ϴ�..\n"); break;
					case 4: player->PlayerStatus[player->Level].Max_San += 10; puts("���������� �ִ����ŷ��� 10 �����߽��ϴ�.\n"); break;
				}
			}
		}
		
	}
}

int CheckWinner(PLAYER* player, PLAYER Lable, MONSTER* monster) {
	switch (CheckHP(player, monster))
	{
	case 0: return 0; break;
	case 1: system("cls");
		puts("����ϼ̽��ϴ�. x�� ���� ���Ǹ� ǥ�Ͻʽÿ�.");
		while (KI != 120);                                                       //'x'
		system("cls");
		puts(" R . ��Ȱ \n ESC . ������");
		while (1) {
			if (KI == 'r') {                                                     //'r'
				CheckStatus(player, Lable);
				DiePlayer(player);
				return 2;
			}
			if (KI == 27) return 1;                                              //ESC
		}
		break;
	case 2: system("cls");
		puts("��Ҵ�..");
		GiveExp(player, monster);
		LevelUP(player, Lable);
		return 2;
		break;
	}
	return 0;
}

int AttackSpd(PLAYER* player, PLAYER Lable, MONSTER* monster, int* life) {
	if (player->PlayerStatus[player->Level].Spd < monster->MonsterStatus.Spd) {
		puts("ĩ, ������ �޾Ҵ�.");
		MonsterHit(player, monster);
		printf("%s�κ��� %d�� �����!\n", monster->name, monster->MonsterStatus.Str);
		*life = CheckWinner(player, Lable, monster);
		switch (*life)
		{
		case 0: break;
		case 1: return 0;
		case 2: return 2;
		}
		PlayerHit(player, monster);
		printf("%s���� %d�� ������� �־���.", monster->name, player->PlayerStatus[player->Level].Str);
		*life = CheckWinner(player, Lable, monster);
		switch (*life)
		{
		case 0: break;
		case 1: return 0;
		case 2: return 2;
		}
	}
	else {
		puts("ı.. �����༮ ������ �ۿ� �ȵǳ�.");
		PlayerHit(player, monster);
		printf("%s���� %d�� ������� �־���.\n", monster->name, player->PlayerStatus[player->Level].Str);
		*life = CheckWinner(player, Lable, monster);
		switch (*life)
		{
		case 0: break;
		case 1: return 0;
		case 2: return 2;
		}
		MonsterHit(player, monster);
		printf("%s�κ��� %d�� �����!", monster->name, monster->MonsterStatus.Str);
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
	printf(" 1 . ���� \n 2 . ��ų \n 3. ������ \n ESC . ����");
}

int battle_status(PLAYER* player, PLAYER Lable, MONSTER* monster, int* life, int* count) {
	battlestatus(player, monster);
	int i = 0;
	switch (KI) {
	case 49: /*����1*/
		i = 1;
		system("cls");
		*life = AttackSpd(player, Lable, monster, life);
		if (*life == 0) i = 0;
		break;
	case 50:/*����2*/
		i = 1;
		break;
	case 51:/*����3*/
		i = 1;
		break;
	case 27:/*ESCŰ*/
		system("cls");
		return 0;
	}
	if (i == 1) {                                                                /*�� ���� Enter*/
		(*count)++;
		while (KI != 13) printf("\n%d turn", *count);
	}
	return *life;
}