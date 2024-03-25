#include "Zombie.hpp"

int main()
{
	Zombie *anun;

	anun = zombieHorde(5, "bobol");
	for (int i = 0; i < 5; i++)
		anun[i].announce();
	delete[] anun;
	return 0;
}