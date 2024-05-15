#include "./Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat buro(1, "aa");
        buro.incBuro();
        // buro.decBuro();
        // buro.decBuro();
        // buro.decBuro();
        std::cout << buro << std::endl;
    }
    catch (std::exception& exp)
    {
        std::cout << "Error: " << exp.what() << std::endl;
    }
    return 0;
}