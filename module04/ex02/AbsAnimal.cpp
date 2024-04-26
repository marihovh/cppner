#include "./AbsAnimal.hpp"

AbsAnimal::AbsAnimal():type("not human")
{
    std::cout << "Default constructor of AbsAnimal is called\n";
    this->brain = new Brain;
}

AbsAnimal::~AbsAnimal()
{
    std::cout << "Destructor of AbsAnimal is called\n";
    // delete brain;
}

AbsAnimal::AbsAnimal(const AbsAnimal& copik)
{
    std::cout << "Copy constructor of AbsAnimal is called\n";
    *this = copik;
}

AbsAnimal& AbsAnimal::operator= (const AbsAnimal& other)
{
    std::cout << "Copy assignment operator for AbsAnimal is called\n";
    this->type = other.type;
    return (*this);
}

void AbsAnimal::setType(std::string tipik)
{
    this->type = tipik;
}

std::string AbsAnimal::getType() const
{
    return (this->type);
}