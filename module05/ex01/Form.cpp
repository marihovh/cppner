#include "./Form.hpp"

Form::Form():_name("esim"), _iSigned(false), _signGrade(1), _execGrade(1)
{
}

Form::~Form()
{
}

Form:: Form(const std::string& name, const int gradeSign, const int gradeExec):
    _name(name), _iSigned(false), _signGrade(gradeSign), _execGrade(gradeExec)
{
    CheckGrade(this->_signGrade);
    CheckGrade(this->_execGrade);
}

std::string const& Form::getName() const
{
    return this->_name;
}

bool Form::getSigned() const
{
    return this->_iSigned;
}

const int& Form::getSignGrade() const
{
    return this->_signGrade;
}

const int& Form::getExecGrade() const
{
    return this->_execGrade;
}

std::ostream& operator<<(std::ostream& stream, const Form& form)
{
    stream << "Name:" << form.getName() << std::endl;
    stream << "is Signed? " << form.getSigned() << std::endl;
    stream << "Sign Grade " << form.getSignGrade() << std::endl;
    stream << "Execute Grade " << form.getExecGrade() << std::endl;
    return stream;
}

void Form::beSigned(const Bureaucrat& buro)
{
    if (buro.getGrade() <= this->_signGrade)
        this->_iSigned = true;
    else
        throw GradeTooLawException();
}
