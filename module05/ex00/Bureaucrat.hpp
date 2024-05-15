#pragma once
#include <iostream>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
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
        std::string const& getName() const;
        Bureaucrat& operator=(const Bureaucrat &other);
        const int& getGrade() const;
        void incBuro();
        void decBuro();
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& buro);