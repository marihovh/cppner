#include "./Bureaucrat.hpp"
#include "./Form.hpp"

int main()
{
    try
    {
        Bureaucrat buro(3, "aa");
        std::cout << buro << std::endl;
        Form form("hamar", 26, 42);
        buro.signForm(form);
    }
    catch (std::exception& exp)
    {
        std::cout << "Error: " << exp.what() << std::endl;
    }
    return 0;
}