#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name("esim"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const int &gde, const std::string& nm):_name(nm)
{
    CheckGrade(gde);
    this->_grade = gde;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        this->_grade = other._grade;
    return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copik)
{
    *this = copik;
}

std::string const& Bureaucrat::getName() const
{
    return this->_name;
}

const int& Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::incBuro()
{
    if (this->_grade == MaxGrade)
        throw GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decBuro()
{
    if (this->_grade == MinGrade)
        throw GradeTooLawException();
    this->_grade++;
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& buro)
{
    stream << buro.getName() << ", bureaucrat grade " << buro.getGrade();
    return stream;
}

void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch (std::exception& exp)
    {
        std::cout << this->getName() << " couldn’t sign " << form.getName() << " because " << exp.what() << std::endl;
    }
}

void CheckGrade(const int& gde)
{
    if (gde > MinGrade)
        throw Bureaucrat::GradeTooLawException();
    if (gde < MaxGrade)
        throw Bureaucrat::GradeTooHighException();
}