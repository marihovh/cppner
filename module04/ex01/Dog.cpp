#include "./Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Default constructor of Dog is called\n";
}

Dog::~Dog()
{
    std::cout << "Default destructor of Dog is called\n";
}

Dog::Dog(const Dog& copik)
{
    std::cout << "Copy constructor of Dog is called\n";
    *this = copik;
}

Dog& Dog::operator= (const Dog& other)
{
    std::cout << "Copy assignment operator for Dog is called\n";
    this->type = other.type;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Gaaaaaaaf Gaaaaaf\n";
}