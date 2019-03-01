#pragma once
#include "Common.h"

int DownwardHit(PLAYER* player, MONSTER* monster);
int StepOn(PLAYER* player, MONSTER* monster);
int Refreshment(PLAYER* player, MONSTER* monster);
int Meditation(PLAYER* player, MONSTER* monster);
int heal(PLAYER* player, MONSTER* monster);
int death(PLAYER* player, MONSTER* monster, int constrant);