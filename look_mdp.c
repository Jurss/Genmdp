#include "look_mdp.h"

void look_mdp(void)
{
	system("sudo chattr -i mdp.txt.aes");
	aesdecrypt();
	
	FILE *fichier = fopen("mdp.txt","r");
	
	char c;

	printf("1.Rechercher un mdp\n2.Afficher tous les afficher\n");
	c = fgetc(stdin);
	if (c == '1')
	{
		viderBuffer();

	}
	else if (c == '2')
	{
		viderBuffer();
		system("cat mdp.txt");
		system("aescrypt -e -p apples mdp.txt");
		system ("rm mdp.txt");
		system("sudo chattr +i mdp.txt.aes");
	}
	fclose(fichier);
}
