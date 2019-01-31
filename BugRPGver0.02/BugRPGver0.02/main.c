#include "Function.h"

int main() {
	int kl = 0;
	PLAYER man;

	srand((unsigned int)time(NULL));

	memset(&man, 0, sizeof(man));
	PLAYER Lable;
	memset(&Lable, 0, sizeof(man));
	PlayerLable(&Lable);
	init();
	while (1)
	{
		kl = _getch();
		if (kl == 13)
		{
			system("cls");
			MakePlayer(&man, &Lable);
			return back_graund(&man);
		}
		if (kl == 120 || kl == 88)
		{
			return 0;
		}
	}
	return 0;
}