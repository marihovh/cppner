#include "./Fixed.hpp"

Fixed& Fixed::operator=(const Fixed& cupik)
{
    std::cout << "Copy assignment operator called\n";
    if (this->fix == cupik.getRawBits())
        return *this;
    this->fix = cupik.getRawBits();
    return *this;
}

Fixed::Fixed(): fix(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed& copik)
{
    std::cout << "Copy constructor called\n";
    this->fix = copik.getRawBits();
}


Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called\n";
    return fix;
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called\n";
    fix = raw;
}