#include "main.h"

int main()
{
	char c;
	printf("1. Cree un Nouveau MDP \n2. Obtenir un de vos MDP\n");
	c = fgetc(stdin);
	if (c == '1')
	{
		viderBuffer();
		add_account();
	}
	else if (c == '2')
	{
		viderBuffer();
		look_mdp();
	}
	return 0;
}
