#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define MAX 15

void add_account(void);
int ft_fgets(char *chaine, int longueur);
void    genMDP(void);
int     saveMDP(char *mdp);
int     genLen(int nbOfLen);
int     randLen(int len);
char    *newMDP(int len, int *tab, char *mdp);
int     ft_len(char *base);
void viderBuffer();

#endif
