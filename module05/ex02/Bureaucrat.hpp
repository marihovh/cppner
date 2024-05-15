#pragma once
#include <iostream>
#include "./AForm.hpp"

class AForm;

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
        void signForm(AForm& form);
        std::string const& getName() const;
        Bureaucrat& operator=(const Bureaucrat &other);
        const int& getGrade() const;
        void incBuro();
        void decBuro();
        void executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& buro);
void CheckGrade(const int& gde);
const int MaxGrade = 1;
const int MinGrade = 150;