#include "./Harl.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    Harl human;

    if (argc == 2)
        human.complain(argv[1]);
    else
        std::cout << "abnormal arguments\n";
    return 0;
}