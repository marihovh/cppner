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
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& stream, const Fixed& fp);

#endif