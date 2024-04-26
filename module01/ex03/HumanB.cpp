#include "HumanB.hpp"
#include <iostream>

HumanB:: HumanB(std::string nm)
{
	name = nm;
}

HumanB::~ HumanB()
{
}
void HumanB::attack()
{
	std::cout << name <<  " attacks with their " <<  gun->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &gn)
{
	gun = &gn;
}