#include "./RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm", 72, 45), _target("esim")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

std::string const& RobotomyRequestForm::getTarget() const
{
    return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->getSigned() || executor.getGrade() > this->getSignGrade())    //esimm
        throw RobotomyFailed();
    std::cout << "drrrrri\n";
    std::cout << this->_target << " has been robotomized successfully 50% of the time\n";
}