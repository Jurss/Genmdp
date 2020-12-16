#include "main.h"

int main(int ac, char *ag[])
{
	if (ac != 2)
	{
		printf("Vous devez entrée votre MDP maitre");
		return 0;
	}
	if (master(ag[1]) != 1)
		return 0;
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
