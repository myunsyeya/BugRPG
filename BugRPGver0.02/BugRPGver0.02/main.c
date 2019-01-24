#include "Function.h"

int main() {
	int kl = 0;
	PLAYER man;
	PLAYER Lable;
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
}