#pragma once
#define NAME_SIZE 32
#define maximum 256
#define Parameternumber 5

typedef struct _tagStatus {
	int Max_Exp;
	int Exp;
	int Max_HP;
	int HP;
	int Max_San;
	int San;
	int Str;
	int Def;
	int Spd;
	int Gold;
}STATUS;

typedef struct _tagItem{
	char name[NAME_SIZE];
	char info[maximum];
	STATUS ItemStatus;
}ITEM;

typedef struct _tagSkill {
	char name[NAME_SIZE];
	int San;
	char Index[maximum];
	int Data;
	int sn;
}SKILL;

typedef struct _tagPlayer {
	char name[NAME_SIZE]; 
	int Level;
	SKILL PlayerSkill[12];
	STATUS PlayerStatus[12];
}PLAYER;

typedef struct _tagMonster{
	char name[NAME_SIZE];
	STATUS MonsterStatus;
}MONSTER;