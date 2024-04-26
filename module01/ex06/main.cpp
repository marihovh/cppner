#include <iostream>
#include "./Harl.hpp"

int main(int argc, char *argv[])
{
    Harl human;

    if (argc == 2)
        human.complain(argv[1]);
    else
        std::cout << "[ Probably complaining about insignificant problems ]\n";
    return 0;
}