#include "./RPN.hpp"

int main(int argc, char *argv[])
{
    RPN lator;

    try
    {
        // std::cout << argc;
    if (argc <= 1)
        throw std::runtime_error("no enough arguments");    
    lator.calculate(argv);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}