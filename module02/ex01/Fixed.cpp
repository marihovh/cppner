#include "./Fixed.hpp"

std::ostream& operator<<(std::ostream& stream, const Fixed& fp)
{
    stream << fp.toFloat();
    return stream;
}

Fixed& Fixed::operator=(const Fixed& cupik)
{
    std::cout << "Copy assignment operator called\n";
    if (this->fix == cupik.fix)
        return *this;
    this->fix = cupik.fix;
    return *this;
}

Fixed::Fixed(const int nb)
{
    fix = nb << bits;
    std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float nb)
{
    fix = (int)roundf(nb * (1 << bits));
    // std::cout << nb << " "<< fix;
    std::cout << "Float constructor called\n";
}

int Fixed::toInt( void ) const
{
    return (this->fix >> bits);
}

float Fixed::toFloat( void ) const
{
    float tmp = (float)this->fix / (1 << this->bits);
    return (tmp);
}

Fixed::Fixed()
{
    std::cout << "Default constructor called\n";
    fix = 0;
}

Fixed::Fixed(const Fixed& copik)
{
    std::cout << "Copy constructor called\n";
    *this = copik;
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
