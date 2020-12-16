#ifndef _LOOK_MDP_H_
#define _LOOK_MDP_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ft_fgets(char *chaine, int longueur);
void look_mdp(void);
void viderBuffer(void);
void aesdecrypt(void);
void aescrypt(void);
int wanted_pass(char *rec);
#endif
