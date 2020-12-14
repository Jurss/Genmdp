#include "add_account.h"
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define MAX 15

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

int     ft_len(char *base)
{
        int i;

        i = 0;
        while(base[i])
        {
                i++;
        }
        return(i);
}

char    *newMDP(int len, int *tab, char *mdp)
{
        int i;
        int j;
        int min;
        int max;
        char base[] = "a8AbcB2d@1Ce6fDE45F8@g2GhH14i6j7kl@m963JKnLMN70Oo1p2P2QR@qrS5sT8345@tUV3uv12WXYZw@x9yz";

        i = 0;
        j = 0;
        min = 0;
        max = ft_len(base);

        srand(time (NULL));
        while (i <= len)
        {
                tab[i] = (rand() % (max - min + 1)) + min;
                i++;
        }
        i = 0;
        while (i < len)
        {
                mdp[i] = base[tab[j]];
                i++;
                j++;
        }
        return (mdp);
}

int     randLen(int len)
{
        int min = 13;
        int max = 16;

        len = 0;
        len = (rand() % (max - min +1)) + min;
        return (len);
}

int     genLen(int nbOfLen)
{
        srand(time (NULL));
        nbOfLen = randLen(nbOfLen);
        return (nbOfLen);
}

int	saveMDP(char *mdp)
{
	FILE *fichier = fopen("mdp.txt","a+");

	fputs(mdp, fichier);
	fputc('\n', fichier);
	fclose(fichier);
	return (1);
}

void	genMDP(void)
{
	int lenMDP;

	lenMDP = 0;
	lenMDP = genLen(lenMDP);//Longeur MDP

	int tab[lenMDP];
	char mdp[lenMDP];

	newMDP(lenMDP,tab,mdp); //Generation du MDP
	saveMDP(mdp);
}

int ft_fgets(char *chaine, int longueur)
{
	char *positionEntree = NULL;

	if (fgets(chaine, longueur, stdin) != NULL)
	{
		positionEntree = strchr(chaine, '\n');
		if (positionEntree != NULL)
			*positionEntree = '\0';
		else
			viderBuffer();
		return 1;
	}
	
	else
	{
		viderBuffer();
		return 0;
	}
}

void add_account(void)
{
	system("sudo chattr -i mdp.txt.aes"); // Autorisation pour ecrire dans le fichier
	FILE *fichier = fopen("mdp.txt", "a+");
	char account[MAX];

	printf("Pour Quelle Site/Appli créé un compte ?(15 caractere max)");
	ft_fgets(account, MAX);
	fputs(account, fichier);
	fputs(" : ", fichier);

	fclose(fichier);

	genMDP();
	aescrypt();
}
