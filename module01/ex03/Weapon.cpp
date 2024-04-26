#include "Weapon.hpp"


Weapon::Weapon(std::string tipik)
{
	type = tipik;
}

Weapon::~Weapon()
{
}

Weapon::Weapon()
{
}

std::string Weapon::getType()
{
	return type;
}

void Weapon::setType(std::string tipo)
{
	type = tipo;
}
