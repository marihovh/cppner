#include "./Intern.hpp"

Intern::Intern()
{
    this->types[0] = "ShrubberyCreationForm";
    this->types[1] = "RobotomyRequestForm";
    this->types[2] = "PresidentialPardonForm";
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(const std::string& name, const std::string& target)
{
    Intern::form[0] = new ShrubberyCreationForm(target);
    Intern::form[1] = new RobotomyRequestForm(target);
    Intern::form[2] = new PresidentialPardonForm(target);
    for (int i = 0; i < 3; i++)
    {
        if (!name.compare(types[i]))
        {
            std::cout << "Intern creates Form\n";
            return (this->form[i]);
        }
    }
    delete form[0];
    delete form[1];
    delete form[2];
    throw NoFormMatch();
}
