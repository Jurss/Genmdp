#include "crypt.h"

void	aescrypt(void)
{
	system("aescrypt -e -p apples mdp.txt");
	system("rm mdp.txt");
	system("sudo chattr +i mdp.txt.aes");
}

void aesdecrypt(void)
{
	system("aescrypt -d -p apples mdp.txt.aes");
	system("rm mdp.txt.aes");

}
