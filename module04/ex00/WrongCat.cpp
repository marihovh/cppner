#include "./WrongCat.hpp"

WrongCat::WrongCat()
{
    this->setType("WrongCat");
    std::cout << "Default constructor of WrongCat is called\n";
}

WrongCat::~WrongCat()
{
    std::cout << "Default destructor of WrongCat is called\n";
}

WrongCat::WrongCat(const WrongCat& copik)
{
    std::cout << "Copy constructor of WrongCat is called\n";
    *this = copik;
}

WrongCat& WrongCat::operator= (const WrongCat& other)
{
    std::cout << "Copy assignment operator for WrongCat is called\n";
    this->type = other.type;
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "MEOWWWWWWWWW\n";
}