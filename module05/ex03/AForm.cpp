#include "./AForm.hpp"

AForm::AForm():_name("esim"), _iSigned(false), _signGrade(1), _execGrade(1)
{
}

AForm::~AForm()
{
}

AForm:: AForm(const std::string& name, const int gradeSign, const int gradeExec):
    _name(name), _iSigned(false), _signGrade(gradeSign), _execGrade(gradeExec)
{
    CheckGrade(this->_signGrade);
    CheckGrade(this->_execGrade);
}

std::string const& AForm::getName() const
{
    return this->_name;
}

bool AForm::getSigned() const
{
    return this->_iSigned;
}

void AForm::setSigned(bool tf)
{
    this->_iSigned = tf;
}

const int& AForm::getSignGrade() const
{
    return this->_signGrade;
}

const int& AForm::getExecGrade() const
{
    return this->_execGrade;
}

std::ostream& operator<<(std::ostream& stream, const AForm& form)
{
    stream << "Name:" << form.getName() << std::endl;
    stream << "is Signed? " << form.getSigned() << std::endl;
    stream << "Sign Grade " << form.getSignGrade() << std::endl;
    stream << "Execute Grade " << form.getExecGrade() << std::endl;
    return stream;
}

void AForm::beSigned(const Bureaucrat& buro)
{
    if (buro.getGrade() <= this->_signGrade)
        this->_iSigned = true;
    else
        throw GradeTooLawException();
}
