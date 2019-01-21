#pragma once
#define NAME_SIZE 32
#define maximum 256
#define ParameterLine 30
#define Parameternumber 5

typedef struct _tagStatus {
	int Level;
	int Max_HP;
	int HP;
	int Max_SP;
	int SP;
	int Str;
	int AC;
	int Gold;
	int Exp;
	int Max_Exp;
}STATUS;

typedef struct _tagItem{
	char name[NAME_SIZE];
	char info[maximum];
	int str;
	int AC;
	int HP;
	int MP;
}ITEM;

typedef struct _tagSkill {
	char name[NAME_SIZE];
	int MP;
	int Data;
}SKILL;

typedef struct _tagPlayer {
	char name[NAME_SIZE];
	SKILL PlayerSkill;
	STATUS PlayerStatus;
}PLAYER;

typedef struct _tagMonster{
	char name[NAME_SIZE];
	STATUS MonsterStatus;
}MONSTER;