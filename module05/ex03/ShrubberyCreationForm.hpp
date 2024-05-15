#pragma once
#include "./AForm.hpp"

class AForm;

class ShrubberyCreationForm: public AForm
{
    private:
        const std::string _target;
        ShrubberyCreationForm();
    public:
        class FormIsNotSigned: public std::exception
        {
            const char* what() const throw()
            {
                return "the Form is not signed\n";
            }
        };
        ShrubberyCreationForm(const std::string& target);
        std::string const& getTarget() const;
        void execute(Bureaucrat const & executor) const;
        ~ShrubberyCreationForm();
};