#include "function.h"

int main() {
	int kl = 0;
	PLAYER man;
	init();
	while (1)
	{
		kl = _getch();
		if (kl == 13)
		{
			system("cls");
			MakePlayer(&man);
			return back_graund(&man);
		}
		if (kl == 120 || kl == 88)
		{
			return 0;
		}
	}
}