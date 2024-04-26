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
        Fixed(Fixed& copik);
        Fixed& operator=(const Fixed& cupik);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif