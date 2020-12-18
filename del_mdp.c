#include "del_mdp.h"

int del_mdp(void)
{
	printf("#################################\n");
	printf("############ATTENTION############\n");
	printf("CETTE OPERATION EST IRREVERSIBLE!\n");
	printf("#################################\n");
	printf("#################################\n");
 
 	char account[15], s[15], s2[3], s3[17];

	printf ("Compte a supprimer ?");
	ft_fgets(account, 15);
	
	system("sudo chattr -i mdp.txt.aes");
	aesdecrypt();

	FILE *fichier, *fichier_tmp;
       
        if (NULL == (fichier = fopen ("mdp.txt", "r")))
                return -1;
        if (NULL == (fichier_tmp = fopen ("mdptmp.txt", "w+")))
                return -1;
 
	while (fscanf (fichier, "%s %s %s", s, s2, s3) == 3)
		if (strcmp (s, account) != 0)
			fprintf (fichier_tmp, "%s %s %s\n", s, s2, s3);

	fclose (fichier);
	fclose (fichier_tmp);

	system("mv mdptmp.txt mdp.txt");
	aescrypt();
	system("sudo chattr +i mdp.txt.aes");
	return 0;
}
