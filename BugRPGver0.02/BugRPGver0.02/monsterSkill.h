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
	/*콩벌레 방어력 한턴간 +2 */
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
	/*3턴간 +10*/
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
	/*1번 사용 가능 - 지속(2턴) str + 10 데미지*/
}

int Survival()
{
	/*생존본능(한 전투에서 1회 사용가능) - 1회 부활 */
}

int Fly(PLAYER *player)
{
	player->PlayerStatus->San = player->PlayerStatus->San - 10;
}

int Pollution()
{
	/*오염시키기(2턴동안 지속되며 턴마다 정신력 - 5 hp ? 1)*/
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
	/*지속 5턴 str*3 데미지*/
}
