#pragma once
#define NAME_SIZE 32
#define MAP_SIZE 64
#define MAXIMUM 256
#define KI (char)_getch()

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
	char info[MAXIMUM];
	int Data;
	STATUS ItemStatus;
}ITEM;

typedef struct _tagSkill {
	char name[NAME_SIZE];
	char Index[MAXIMUM];
	int SkillNumber;
}SKILL;

typedef struct _tagPlayer {
	char name[NAME_SIZE]; 
	int Level;
	int SkillLimit;
	SKILL PlayerSkill[10];
	STATUS PlayerStatus[12];
	STATUS addStatus;
}PLAYER;

typedef struct _tagMonster{
	char name[NAME_SIZE];
	SKILL MonsterSkill[4];
	STATUS MonsterStatus;
}MONSTER;

typedef struct position{
	int x;
	int y;
}POS;