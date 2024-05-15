#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("esim"), grade(150)
{
}

Bureaucrat::Bureaucrat(const int &gde, const std::string& nm):name(nm)
{
    if (gde > 150)
        throw GradeTooLawException();
    if (gde < 1)
        throw GradeTooHighException();
    this->grade = gde;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        this->grade = other.grade;
    return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copik)
{
    *this = copik;
}

std::string const& Bureaucrat::getName() const
{
    return this->name;
}

const int& Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::incBuro()
{
    if (this->grade == 1)
        throw GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decBuro()
{
    if (this->grade == 150)
        throw GradeTooLawException();
    this->grade++;
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& buro)
{
    stream << buro.getName() << ", bureaucrat grade " << buro.getGrade();
    return stream;
}