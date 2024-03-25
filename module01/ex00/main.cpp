#include "Zombie.hpp"

int main()
{
	Zombie *anun;

	anun = newZombie("bobol");
	anun.announce();
	return 0;
}