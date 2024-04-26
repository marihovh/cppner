#include "./WrongAnimal.hpp"

WrongAnimal::WrongAnimal():type("not human")
{
    std::cout << "Default constructor of WrongAnimal is called\n";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Destructor of WrongAnimal is called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& copik)
{
    std::cout << "Copy constructor of WrongAnimal is called\n";
    *this = copik;
}

WrongAnimal& WrongAnimal::operator= (const WrongAnimal& other)
{
    std::cout << "Copy assignment operator for WrongAnimal is called\n";
    this->type = other.type;
    return (*this);
}

void WrongAnimal::makeSound() const
{
    std::cout << "making some noise like wrong animals\n";
}

void WrongAnimal::setType(std::string tipik)
{
    this->type = tipik;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}