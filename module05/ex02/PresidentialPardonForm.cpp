#include "./PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardonForm", 25, 5), _target("esim")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

std::string const& PresidentialPardonForm::getTarget() const
{
    return this->_target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!this->getSigned() || executor.getGrade() > this->getSignGrade())
        throw FormIsNotSigned();
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox.\n";
}