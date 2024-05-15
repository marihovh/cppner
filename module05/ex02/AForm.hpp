#pragma once
#include <iostream>
#include <fstream>
#include "./Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    protected:
        const std::string _name;
        bool _iSigned;
        const int _signGrade;
        const int _execGrade;
    public:
        virtual void execute(Bureaucrat const & executor) const = 0;
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
        AForm();
        virtual ~AForm();
        AForm(const std::string& name, const int gradeSign, const int gradeExec);
        std::string const& getName() const;
        bool getSigned() const;
        void setSigned(bool tf);
        void beSigned(const Bureaucrat& buro);
        const int& getSignGrade() const;
        const int& getExecGrade() const;

};