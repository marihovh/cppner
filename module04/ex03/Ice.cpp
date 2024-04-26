#include "Ice.hpp"

AMateria* Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *";
}

Ice::Ice():AMateria("Ice")
{
}

Ice::Ice(std::string const & type):AMateria(type)
{
}

Ice::Ice(const Ice &copik):AMateria(copik)
{
}

Ice &Ice::operator=(const Ice &other)
{
	AMateria::operator=(other);
	return (*this);
}

Ice::~Ice()
{
}