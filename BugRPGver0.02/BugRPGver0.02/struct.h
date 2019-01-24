#pragma once
#define NAME_SIZE 32
#define maximum 256
#define ParameterLine 32
#define Parameternumber 5

typedef struct _tagStatus {
	int Level;
	int Max_Exp[maximum];
	int Exp;
	int Max_HP[maximum];
	int HP;
	int Max_San[maximum];
	int San;
	int Str[maximum];
	int Def[maximum];
	int Spd[maximum];
	int Gold;
}STATUS;

typedef struct _tagItem{
	char name[NAME_SIZE];
	char info[maximum];
	int Str;
	int Def;
	int HP;
	int san;
}ITEM;

typedef struct _tagSkill {
	char name[NAME_SIZE];
	int San;
	int Data;
}SKILL;

typedef struct _tagPlayer {
	char name[NAME_SIZE]; 
	SKILL PlayerSkill;
	STATUS PlayerStatus;
}PLAYER;

typedef struct _tagMonster{
	char name[NAME_SIZE];
	int Max_HP;
	int HP;
	int Str;
	int Def;
	int Gold;
	int Exp;
	int Spd;
}MONSTER;