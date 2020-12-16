#include "look_mdp.h"

void look_mdp(void)
{	
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
		system("sudo chattr -i mdp.txt.aes");
 		aesdecrypt();
		
		FILE *fichier = fopen("mdp.txt","r");
		
		system("cat mdp.txt");
		aescrypt();
		fclose(fichier);
	}
}
