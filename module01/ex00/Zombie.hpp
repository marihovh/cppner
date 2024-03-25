#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>


class Zombie
{
private:
	std::string		name;
public:
	Zombie();
	~Zombie();
	void set_n(std::string nm) {name = nm;}
	void announce( void );
};


void Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ" << std::endl;
}

Zombie::Zombie(std::string nm):name(nm)
{
}

Zombie::~Zombie()
{
	std::cout << "I am destroyed\n";
}

// Zombie* zombieHorde( int N, std::string name );

#endif