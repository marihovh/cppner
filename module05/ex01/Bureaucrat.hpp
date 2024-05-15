#pragma once
#include <iostream>
#include "./Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:
        class GradeTooHighException: public std::exception
        {
            const char* what() const throw()
            {
                return "the Grade is too High";
            }
        };
        class GradeTooLawException: public std::exception
        {
            const char* what() const throw()
            {
                return "The Grade is too Low";
            }
        };
        Bureaucrat();
        Bureaucrat(const Bureaucrat &copik);
        Bureaucrat(const int &grade, std::string const& name);
        ~Bureaucrat();
        void signForm(Form& form);
        std::string const& getName() const;
        Bureaucrat& operator=(const Bureaucrat &other);
        const int& getGrade() const;
        void incBuro();
        void decBuro();
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& buro);
void CheckGrade(const int& gde);
const int MaxGrade = 1;
const int MinGrade = 150;