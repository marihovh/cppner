#pragma once
#include <iostream>
#include "./Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _iSigned;
        const int _signGrade;
        const int _execGrade;
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
        Form();
        ~Form();
        Form(const std::string& name, const int gradeSign, const int gradeExec);
        std::string const& getName() const;
        bool getSigned() const;
        void beSigned(const Bureaucrat& buro);
        const int& getSignGrade() const;
        const int& getExecGrade() const;

};

std::ostream& operator<<(std::ostream& stream, const Form& form);