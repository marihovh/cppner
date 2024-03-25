#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"

class  HumanA
{
private:
	Weapon *gun;
	std::string name;
public:
	HumanA(std::string name, Weapon &gn);
	void attack();
	~ HumanA();
};




#endif