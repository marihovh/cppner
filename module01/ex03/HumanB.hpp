#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"

class  HumanB
{
private:
	Weapon *gun;
	std::string name;
public:
	HumanB(std::string nm);
	void setWeapon(Weapon &gn);
	void attack();
	~ HumanB();
};




#endif