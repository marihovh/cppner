#include "./Harl.hpp"
#include <string>

void Harl::debug()
{
    std::cout << "[DEBUG]\n";
    std::cout<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n I really do!\n";
}

void Harl::info()
{
    std::cout << "[INFO]\n";
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning()
{
    std::cout << "[WARNING]\n";
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error()
{
    std::cout << "[ERROR]\n";
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level)
{
    int i = 0;
    while(i < 4)
    {
        if (!level.compare(Harl::levels[i]))
            break ;
        i++;
    }
    switch (i)
    {
        case 0:
            (this->*backup[0])();
        case 1:
            (this->*backup[1])();
        case 2:
            (this->*backup[2])();
        case 3:
            (this->*backup[3])();
            break ;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
            break ;
    }
}

Harl::Harl()
{
    levels[0] = "DEBUG";
    levels[1] = "INFO";
    levels[2] = "WARNING";
    levels[3] = "ERROR";
    Harl::backup[0] = &Harl::debug;
    Harl::backup[1] = &Harl::info;
    Harl::backup[2] = &Harl::warning;
    Harl::backup[3] = &Harl::error;
}