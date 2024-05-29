#include "./ScalarConverter.hpp"

void parse(std::string value)
{
    if (value != "nan" && value != "+inf" && value != "-inf" && value != "nanf" && value != "+inff" && value != "-inff")
    {
            for (unsigned int i = 0; i < value.size(); i++)
            {   
                if (value[i] != '.' && value[i] != 'f' && value[i] != '+' && value[i] != '-' && !std::isdigit(value[i]))
                    throw ScalarConverter::ImpossibleToConvert();
            }
    }
}

void to_char(std::string value)
{
    int num = std::atoi(value.c_str());
    if ((value.size() > 1 && !num))
        throw ScalarConverter::ImpossibleToConvert();
    if (!std::isprint(num))
        throw ScalarConverter::NonDisplayable();
    std::cout << static_cast<char>(num) << std::endl;
}

void to_int(std::string value)
{
    long num = std::atol(value.c_str());

    if (value.size() > 1 && !num)
        throw ScalarConverter::ImpossibleToConvert();
    if (num <= INT_MIN || num >= INT_MAX)
        throw ScalarConverter::ImpossibleToConvert();
    std::cout << num << std::endl;
}

void to_float(std::string value)
{
    float num = std::atof(value.c_str());

    if (static_cast<int>(num) - num == 0)
        std::cout << num << ".0";
    else
        std::cout << num;
    std::cout << "f" << std::endl;
}

void to_double(std::string value)
{
    double num = std::atof(value.c_str());

    if (static_cast<int>(num) - num == 0)
        std::cout << num << ".0";
    else
        std::cout << num;
    std::cout << std::endl;
}

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(std::string value)
{
    try
    {
        parse(value);
    }
    catch (std::exception& exp)
    {
        std::cout << exp.what() << std::endl;
        return ;
    }
    try
    {
        std::cout << "char: ";
        to_char(value);
    }
    catch (std::exception& exp)
    {
        std::cout << exp.what() << std::endl;
    }
    try
    {
        std::cout << "int: ";
        to_int(value);
    }
    catch (std::exception& exp)
    {
        std::cout << exp.what() << std::endl;
    }
    try
    {
        std::cout << "float: ";
        to_float(value);
    }
    catch (std::exception& exp)
    {
        std::cout << exp.what();
    }
    try
    {
        std::cout << "double: ";
        to_double(value);
    }
    catch (std::exception& exp)
    {
        std::cout << exp.what();
    }
}