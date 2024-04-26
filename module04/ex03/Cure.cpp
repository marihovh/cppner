#include "Cure.hpp"

AMateria* Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *\n";
}

Cure::Cure():AMateria("Cure")
{
}

Cure::Cure(std::string const & type):AMateria(type)
{
}

Cure::Cure(const Cure &copik):AMateria(copik)
{
}

Cure &Cure::operator=(const Cure &other)
{
    AMateria::operator=(other);
	return (*this);
}

Cure::~Cure()
{
}