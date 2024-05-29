#pragma once
#include <iostream>
#include <cstring>
#include <limits>

class ScalarConverter
{
    private:
        ScalarConverter();
    public:
        ~ScalarConverter();
        static void convert(std::string arg);
        class ImpossibleToConvert: public std::exception
        {
            const char* what() const throw()
            {
                return "impossible";
            }
        };
        class NonDisplayable: public std::exception
        {
            const char* what() const throw()
            {
                return "Non displayable";
            }
        };
};