#include "./ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():AForm("ShrubberyCreationForm", 145, 137), _target("esim")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string const& ShrubberyCreationForm::getTarget() const
{
    return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream outputFile;

    if (!this->getSigned() || executor.getGrade() > this->getSignGrade())    //esimm
        throw FormIsNotSigned();
    outputFile.open(this->getTarget() + "_shruberry");
    if (!outputFile)
        throw std::runtime_error("Error: Unable to open file.\n");
    outputFile << "    __ _.--..--._ _ \n";
    outputFile << " .-' _/   _/\\_   \\_'-.\n";
    outputFile << "|__ /   _/\\__/\\_   \\__|\n";
    outputFile << "   |___/\\_\\__/  \\___|\n";
    outputFile << "          \\__/\n";
    outputFile << "          \\__/\n";
    outputFile << "           \\__/\n";
    outputFile << "            \\__/\n";
    outputFile << "        ____\\__/___\n";
    outputFile << "   . - '             ' -.\n";
    outputFile << "  /                      \\\n";
    outputFile << "~~~~~~~  ~~~~~ ~~~~~  ~~~ ~~~  ~~~~~\n";
    outputFile << "  ~~~   ~~~~~   ~!~~   ~~ ~  ~ ~ ~\n";
    outputFile.close();
}