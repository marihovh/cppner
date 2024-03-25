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

std::string Weapon::get_type()
{
	return type;
}

void Weapon::set_type(std::string tipo)
{
	type = tipo;
}
