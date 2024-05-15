#pragma once
#include <iostream>
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"

class AForm;

class Intern
{
    private:
        std::string types[3];
        AForm* form[3];
    public:
        class NoFormMatch: public std::exception
        {
            const char* what() const throw()
            {
                return "There is no such Form";
            }
        };
        Intern();
        Intern(const Intern &copik);
        ~Intern();
        AForm *makeForm(const std::string& name, const std::string& target);
};