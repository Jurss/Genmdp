#include "look_mdp.h"

void look_mdp(void)
{	
	char c;

	printf("1.Rechercher un mdp\n2.Afficher tous les afficher\n");
	c = fgetc(stdin);
	if (c == '1')
	{
		char want[15];
		viderBuffer();

		printf("Pour quel compte ?\n");
		ft_fgets(want, 15);
		
		wanted_pass(want);
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

int wanted_pass(char *rec)
{
	system("sudo chattr -i mdp.txt.aes");
	aesdecrypt();
        FILE* compte = fopen("mdp.txt","r");
        char line[25];
        char wanted[25];
        int len;
	int i = 0;
        while (fgets(line,sizeof line, compte))                 //recherche rec
        {
                if (strstr(line, rec))
                {
                        len = strlen(line);                     //
                        fseek(compte, -len, SEEK_CUR);          //
                        fgets(wanted, sizeof wanted, compte);   //reviens au debut de la ligne
                        while (wanted[i] != '\n')
			{
				wanted[i] = '\0';
				i++;
			}			//et l'affiche
                        break;                                  //
                }

        }
        if (feof(compte))
        {
                printf("Ce compte est introuvable ! Verifier l'ortographe de celui-ci.\n");
        }
	aescrypt();
	system("sudo chattr +i mdp.txt.aes");
        fclose(compte);
        return (1);
}
