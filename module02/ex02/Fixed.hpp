#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
    private:
        int fix;
        static const int bits = 8;
    public:
        Fixed();
        Fixed(const int nb);
        Fixed(const float nb);
        Fixed(const Fixed& copik);
        int toInt( void ) const;
        float toFloat( void ) const;
        Fixed& operator=(const Fixed& cupik);
        bool operator<(const Fixed& rhs);
        bool operator<=(const Fixed& rhs);
        bool operator>(const Fixed& rhs);
        bool operator>=(const Fixed& rhs);
        bool operator==(const Fixed& rhs);
        bool operator!=(const Fixed& rhs);
        Fixed operator+(const Fixed& rhs);
        Fixed operator++(int);
        Fixed& operator++();
        Fixed operator--(int);
        Fixed& operator--();
        Fixed operator-(const Fixed& rhs);
        Fixed operator*(const Fixed& rhs);
        Fixed operator/(const Fixed& rhs);
        static Fixed& min(Fixed& lhs, Fixed& rhs);
        static const Fixed& min(const Fixed& lhs, const Fixed& rhs);
        static Fixed& max(Fixed& lhs, Fixed& rhs);
        static const Fixed& max(const Fixed& lhs, const Fixed& rhs);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

std::ostream& operator << (std::ostream& stream, const Fixed& fp);

#endif