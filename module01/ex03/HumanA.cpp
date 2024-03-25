#include "HumanA.hpp"
#include <iostream>

HumanA:: HumanA(std::string nm, Weapon &gn)
{
	name = nm;
	gun = &gn;
}

HumanA::~ HumanA()
{
}

void HumanA::attack()
{
	std::cout << name <<  " attacks with their " << gun->get_type() << std::endl;
}