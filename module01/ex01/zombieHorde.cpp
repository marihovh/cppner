#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *horde;

	horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].set_n(name);
	return horde;
}