#include "./AAnimal.hpp"

AAnimal::AAnimal():type("not human")
{
    std::cout << "Default constructor of AAnimal is called\n";
    this->brain = new Brain;
}

AAnimal::~AAnimal()
{
    std::cout << "Destructor of AAnimal is called\n";
    delete brain;
}

AAnimal::AAnimal(const AAnimal& copik)
{
    std::cout << "Copy constructor of AAnimal is called\n";
    *this = copik;
}

AAnimal& AAnimal::operator= (const AAnimal& other)
{
    std::cout << "Copy assignment operator for AAnimal is called\n";
    this->type = other.type;
    return (*this);
}

void AAnimal::setType(std::string tipik)
{
    this->type = tipik;
}

std::string AAnimal::getType() const
{
    return (this->type);
}