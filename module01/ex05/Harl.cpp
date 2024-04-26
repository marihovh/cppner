#include "./Harl.hpp"
#include <string>

void Harl::debug()
{
    std::cout<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level)
{
    for (int i = 0; i < 4;i++)
    {  
        if (!level.compare(levels[i]))
        {
            (this->*backup[i])();
            return ;
        }
    }
    std::cout << "Error\n";
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