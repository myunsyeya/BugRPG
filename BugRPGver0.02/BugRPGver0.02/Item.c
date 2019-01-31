#include "Item.h"

void MakeItemList(ITEM* ItemList) {
	FILE* ItemFile = NULL;
	errno_t err = fopen_s(&ItemFile, "ItemList.txt", "rt");
	if (err != 0) puts("무언가...무언가 잘못됨");
	char line[64];
	int number = 0;
	int count = 0;
	while (fgets(line, sizeof(line), ItemFile) != NULL) {
		switch (number % 9) {
		case 0: count = number / 9;
			int i = 0;
			for (i = 0; line[i]; i++) ItemList[count].name[i] = line[i];
			ItemList[count].name[i - 1] = (char)NULL; break;
		case 1: ItemList->ItemStatus.HP = atoi(line); break;
		case 2: ItemList->ItemStatus.San = atoi(line); break;
		case 3: ItemList->ItemStatus.Str = atoi(line); break;
		case 4: ItemList->ItemStatus.Def = atoi(line); break;
		default: i = 0;
			for (i = 0; line[i]; i++) ItemList[count].info[i] = line[i];
			ItemList[count].info[i - 1] = (char)NULL; break;
		}
		number++;
	}
	fclose(ItemFile);
}
