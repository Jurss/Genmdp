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
	clear();
	printf("1. Cree un Nouveau MDP \n2. Obtenir un de vos MDP\n3.Supprimer un mot de passe");
	c = fgetc(stdin);
	
	if (c == '1')
	{
		viderBuffer();
		clear();
		add_account();
	}
	else if (c == '2')
	{
		viderBuffer();
		clear();
		look_mdp();
	}
	else if (c == '3')
	{
		viderBuffer();
		clear();
		del_mdp();
	}
	return 0;
}
