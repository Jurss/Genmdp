#include "main.h"

int main()
{
	printf("1. Cree un Nouveau MDP \n2. Obtenir un de vos MDP");
	if (fgetc(stdin) == 49)
	{
		viderBuffer();
		add_account();
	}
	return 0;
}
