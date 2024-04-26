#include "./Animal.hpp"

Animal::Animal():type("not human")
{
    std::cout << "Default constructor of Animal is called\n";
    this->brain = new Brain;
}

Animal::~Animal()
{
    std::cout << "Destructor of Animal is called\n";
    delete brain;
}

Animal::Animal(const Animal& copik)
{
    std::cout << "Copy constructor of Animal is called\n";
    *this = copik;
}

Animal& Animal::operator= (const Animal& other)
{
    std::cout << "Copy assignment operator for Animal is called\n";
    this->type = other.type;
    return (*this);
}

void Animal::setType(std::string tipik)
{
    this->type = tipik;
}

std::string Animal::getType() const
{
    return (this->type);
}