#pragma once
#include "Common.h"

void MakePlayerName(PLAYER* player);
void MakePlayerLable(PLAYER* Lable);
void CheckStatus(PLAYER* player, PLAYER Lable, int level);
void MakePlayer(PLAYER* player, PLAYER Lable);
void AddStatusSave(PLAYER* player, PLAYER* addstatus, PLAYER Lable);
void AddStatusApply(PLAYER* player, PLAYER* addstatus);
void CheckAddStatus(PLAYER* player);