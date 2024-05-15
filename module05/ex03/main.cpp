#include "./Bureaucrat.hpp"
#include "./AForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern es;
    Bureaucrat buro(10, "asalam");
    std::cout << buro << std::endl;
    try
    {
        AForm* a = es.makeForm("ShrubberyCreationForm", "asalam");
        buro.signForm(*a);
    }
    catch (std::exception& exp)
    {
        std::cout << exp.what() << std::endl;
    }
    PresidentialPardonForm form1(buro.getName());
    try
    {
        form1.execute(buro);
    }
    catch(std::exception& exp)
    {
        std::cout << exp.what() << std::endl;
    }
    return 0;
}
