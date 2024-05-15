#pragma once
#include "./AForm.hpp"

class AForm;

class RobotomyRequestForm: public AForm
{
    private:
        const std::string _target;
        RobotomyRequestForm();
    public:
        class RobotomyFailed: public std::exception
        {
            const char* what() const throw()
            {
                return "Robotomy failed\n";
            }
        };
        RobotomyRequestForm(const std::string& target);
        std::string const& getTarget() const;
        void execute(Bureaucrat const & executor) const;
        ~RobotomyRequestForm();
};