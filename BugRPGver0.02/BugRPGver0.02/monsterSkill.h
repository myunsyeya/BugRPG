#pragma once
#include "function.h"

int NormalAttack (PLAYER *player,MONSTER *monster)
{
	player->PlayerStatus->HP = player->PlayerStatus->HP - monster->MonsterStatus.Str;
}

int Snap (PLAYER *player,MONSTER *monster)
{
	player->PlayerStatus->HP = player->PlayerStatus->HP - (monster->MonsterStatus.Str +1);
}

int Climbing (PLAYER *player)
{
	player->PlayerStatus->San = player->PlayerStatus->San - 4;
}

int EarAccess1 (PLAYER *player)
{
	player->PlayerStatus->San = player->PlayerStatus->San - 8;
}

int FoodPoisoning (PLAYER *player)
{

}

int EarAccess2 (PLAYER *player)
{
	player->PlayerStatus->San = player->PlayerStatus->San - 9;
}

int Blood (PLAYER *player,MONSTER *monster)
{
	player->PlayerStatus->HP = player->PlayerStatus->HP - 2;
	monster->MonsterStatus.HP = monster->MonsterStatus.HP + 2;
}

int Harden()
{
	/*����� ���� ���ϰ� +2 */
}

int Rolling (PLAYER *player,MONSTER *monster)
{
	player->PlayerStatus->HP = player->PlayerStatus->HP - monster->MonsterStatus.Str * 2;
}

int Passive()
{

}

int Scratch(PLAYER *player)
{
	player->PlayerStatus->HP = player->PlayerStatus->HP - 45;
}

int Chameleon()
{
	/*3�ϰ� +10*/
}

int eat(MONSTER *monster)
{
	monster->MonsterStatus.HP = monster->MonsterStatus.HP + ((monster->MonsterStatus.Max_HP - monster->MonsterStatus.HP) / 2);
}

int Passive1()
{

}

int NewSnap(PLAYER *player,MONSTER *monster)
{
	player->PlayerStatus->HP = player->PlayerStatus->HP - monster->MonsterStatus.Str * 2;
}

int Passive2(PLAYER *player,MONSTER *monster)
{
	player->PlayerStatus->San = player->PlayerStatus->San - monster->MonsterStatus.Str;
}

int Trunk(PLAYER *player,MONSTER *monster)
{
	player->PlayerStatus->HP = player->PlayerStatus->HP - monster->MonsterStatus.Str * 3;
}

int Passive3()
{

}

int BeeNeedle(PLAYER *player, MONSTER *monster)
{
	player->PlayerStatus->HP = player->PlayerStatus->HP - (monster->MonsterStatus.Str + 10);
}

int BeePoisonNeedie()
{
	/*1�� ��� ���� - ����(2��) str + 10 ������*/
}

int Survival()
{
	/*��������(�� �������� 1ȸ ��밡��) - 1ȸ ��Ȱ */
}

int Fly(PLAYER *player)
{
	player->PlayerStatus->San = player->PlayerStatus->San - 10;
}

int Pollution()
{
	/*������Ű��(2�ϵ��� ���ӵǸ� �ϸ��� ���ŷ� - 5 hp ? 1)*/
}

int Passive4()
{

}

int Passive5()
{

}

int CrabFoot(PLAYER *player, MONSTER *monster)
{
	player->PlayerStatus->HP = player->PlayerStatus->HP - monster->MonsterStatus.Str * 2;
}

int PoisonTail()
{
	/*���� 5�� str*3 ������*/
}
