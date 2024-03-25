#include "Zombie.hpp"

void Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ" << std::endl;
}

Zombie::Zombie()
{
}

Zombie::Zombie(std::string nm):name(nm)
{
}

Zombie::~Zombie()
{
	std::cout << "I am destroyed\n";
}

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