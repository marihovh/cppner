#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

class Weapon
{
private:
	std::string type;
public:
	Weapon(std::string tipik);
	Weapon();
	~Weapon();
	std::string getType();
	void setType(std::string tipo);
};

#endif