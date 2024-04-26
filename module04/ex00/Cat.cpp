#include "./Cat.hpp"

Cat::Cat()
{
    this->setType("Cat");
    std::cout << "Default constructor of Cat is called\n";
}

Cat::~Cat()
{
    std::cout << "Default destructor of Cat is called\n";
}

Cat::Cat(const Cat& copik)
{
    std::cout << "Copy constructor of Cat is called\n";
    *this = copik;
}

Cat& Cat::operator= (const Cat& other)
{
    std::cout << "Copy assignment operator for Cat is called\n";
    this->type = other.type;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "MEOWWWWWWWWW\n";
}