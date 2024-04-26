#include "./Zombie.hpp"


void Zombie::announce( void )
{
	if (name[0] == '\0')
		return ;
	std::cout << name << ": BraiiiiiiinnnzzzZ" << std::endl;
}

Zombie::Zombie(std::string nm):name(nm)
{
}

Zombie::Zombie()
{
}

void Zombie::set_n(std::string nm)
{
	name = nm;
}

Zombie::~Zombie()
{
	std::cout << "I am destroyed\n";
}

Zombie* newZombie( std::string name )
{
	Zombie *anun = new Zombie();

	anun->set_n(name);
	return (anun);
}

void randomChump( std::string name )
{
	Zombie anun(name);

	anun.announce();
}