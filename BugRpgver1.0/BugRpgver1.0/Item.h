#pragma once
#include "Common.h"

void MakeItemList(ITEM* ItemList);
void MakePlayerItem(PLAYER* player, ITEM* ItemList, int number, int itemnumber);
void InstallPlayerEquipment(PLAYER* player, int number);
void BattleItem(PLAYER* player, int* itemnumber);
void FunctionItem(PLAYER* player, ITEM* ItemList, int itemnumber);
void ReturnFunctionItem(PLAYER* player, ITEM* ItemList, int itemnumber);