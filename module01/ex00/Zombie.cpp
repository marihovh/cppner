#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie *anun = NULL;

	anun->set_n(name);
	return (anun);
}

// Zombie* zombieHorde( int N, std::string name );

void randomChump( std::string name )
{
	Zombie anun(name);

	anun.announce();
}
