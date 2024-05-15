#include "./Bureaucrat.hpp"
#include "./AForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat buro(100, "asalam");
    std::cout << buro << std::endl;
    ShrubberyCreationForm form1(buro.getName());
    buro.signForm(form1);
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
