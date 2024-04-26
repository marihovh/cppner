#include "./Fixed.hpp"

std::ostream& operator<<(std::ostream& stream, const Fixed& fp)
{
    stream << fp.toFloat();
    return stream;
}

bool Fixed::operator<(const Fixed& rhs)
{
    return (this->fix < rhs.fix);
}

bool Fixed::operator<=(const Fixed& rhs)
{
    return (this->fix <= rhs.fix);
}

bool Fixed::operator>(const Fixed& rhs)
{
    return (this->fix > rhs.fix);
}

bool Fixed::operator>=(const Fixed& rhs)
{
    return (this->fix >= rhs.fix);
}

bool Fixed::operator==(const Fixed& rhs)
{
    return (this->fix == rhs.fix);
}

bool Fixed::operator!=(const Fixed& rhs)
{
    return (this->fix != rhs.fix);
}

Fixed Fixed::operator+(const Fixed& rhs)
{
    Fixed tmp;
    tmp.fix = this->fix + rhs.fix;
    return (tmp);
}

Fixed Fixed::operator-(const Fixed& rhs)
{
    Fixed tmp;

    tmp.fix = this->fix - rhs.fix;
    return (tmp);
}

Fixed Fixed::operator*(const Fixed& rhs)
{
    Fixed tmp(this->toFloat() * rhs.toFloat());
    return (tmp);
}

Fixed& Fixed::max(Fixed& lhs, Fixed& rhs)
{
    if (lhs.getRawBits() > rhs.getRawBits())
        return lhs;
    return rhs;
}

Fixed& Fixed::min(Fixed& lhs, Fixed& rhs)
{
    if (lhs.getRawBits() < rhs.getRawBits())
        return lhs;
    return rhs;
}

const Fixed& Fixed::min(const Fixed& lhs, const Fixed& rhs)
{
    if (lhs.getRawBits() < rhs.getRawBits())
        return lhs;
    return rhs;
}

const Fixed& Fixed::max(const Fixed& lhs, const Fixed& rhs)
{
    if (lhs.getRawBits() > rhs.getRawBits())
        return lhs;
    return rhs;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp;

    tmp.fix = this->fix++;
    return (tmp);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp;

    tmp.fix = this->fix--;
    return (tmp);
}

Fixed& Fixed::operator++()
{   
    (this)->fix++;
    return (*this);
}

Fixed& Fixed::operator--()
{   
    this->fix--;
    return (*this);
}

Fixed Fixed::operator/(const Fixed& rhs)
{
    Fixed tmp;

    if (rhs.fix == 0)
    {
        std::cout << "dont do it\n";
        return (0);
    }
    tmp.fix = this->fix / rhs.fix;
    return (tmp);
}

Fixed& Fixed::operator=(const Fixed& cupik)
{
    if (this->fix == cupik.fix)
        return *this;
    this->fix = cupik.fix;
    return *this;
}

Fixed::Fixed(const int nb)
{
    fix = nb << bits;
}

Fixed::Fixed(const float nb)
{
    fix = (int)roundf(nb * (1 << bits));
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
    fix = 0;
}

Fixed::Fixed(const Fixed& copik)
{
    *this = copik;
}


Fixed::~Fixed()
{
}

int Fixed::getRawBits( void ) const
{
    return fix;
}

void Fixed::setRawBits( int const raw )
{
    fix = raw;
}
