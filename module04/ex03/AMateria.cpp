#include "./AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
    this->type = type;
}


std::string const &AMateria::getType() const
{
    std::cout << "mamamamamamama\n";
    return this->type;
}

AMateria::AMateria()
{
}

void AMateria::setType(std::string const &type)
{
    this->type = type;
}

AMateria::~AMateria()
{
}

AMateria::AMateria(const AMateria& copik)
{
    *this = copik;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this == &other)
		return(*this);
	this->type = other.type;
    return (*this);
}

void AMateria::use(ICharacter& target)
{
    (void)target;
    std::cout << "a\n";
}