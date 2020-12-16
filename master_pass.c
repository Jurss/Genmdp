#include "master_pass.h"

int master(char *ag)
{
	char master_pass[] = "171428382004";
	int cmp = 12;

	cmp = strcmp(master_pass, ag);
	if (cmp == 0)
		return 1;
	else
		printf("Mot de passe Errone, relancez le programme \n");
	return 0;
}
