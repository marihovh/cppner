#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie
{
private:
	std::string		name;
public:
	Zombie();
	Zombie(std::string nm);
	~Zombie();
	void set_n(std::string nm);
	void announce( void );
};

Zombie* newZombie(std::string name);
void randomChump( std::string name );

#endif