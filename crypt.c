#include "crypt.h"

void	aescrypt()
{
	system("aescrypt -e -p apples mdp.txt");
	system("rm mdp.txt");
	system("sudo chattr +i mdp.txt.aes");
}
