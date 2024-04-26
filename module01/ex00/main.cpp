#include "Zombie.hpp"

int main()
{
	Zombie *anun = NULL;

	anun = newZombie("bobol");
	anun->announce();
	delete anun;
	return 0;
}