#include "./RPN.hpp"

int operate(int first, int second, char op)
{
    if (op == '-')
        return (first - second);
    if (op == '+')
        return (first + second);
    if (op == '*')
        return (first * second);
    if (op == '/')
    {
        if (second == 0)
            throw std::runtime_error("error division by zero");
        return (first / second);
    }
    return 0;
}

RPN::RPN()
{
}

RPN::~RPN()
{
}

std::string trim(const std::string &str)
{
    std::string result;
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
    {
        if (!std::isspace(*it))
        {
            result += *it;
        }
    }
    return result;
}

std::string preparse(char **arg)
{
    std::string ret = arg[1];

    for (int i = 1; arg[i + 1]; i++)
    {
        std::string tmp = arg[i + 1];
        ret += " " + tmp;
    }
    return ret;
}

void RPN::parse(char **arg)
{
    this->_argument = preparse(arg);
    size_t i = -1;
    while (++i < this->_argument.length())
        if (!std::isspace(this->_argument[i]))
            break ;
    if (i == this->_argument.length())
        throw std::runtime_error("empty");
    for (size_t i = 0; i < this->_argument.length(); i++)
    {
        if (this->_argument[i] != '+' && this->_argument[i] != '-' && this->_argument[i] != '*' && this->_argument[i] != '/' && !std::isspace(this->_argument[i]) && !std::isdigit(this->_argument[i]))
            throw std::runtime_error("no proper arguments");
        if (std::isdigit(this->_argument[i]) && this->_argument[i + 1] && std::isdigit(this->_argument[i + 1]))
            throw std::runtime_error("no proper arguments");
        if ((this->_argument[i] == '+' || this->_argument[i] == '-' || this->_argument[i] == '*' || this->_argument[i] == '/') && this->_argument[i + 1] && !(std::isspace(this->_argument[i + 1]) || std::isdigit(this->_argument[i + 1])))
        {
            throw std::runtime_error("no proper arguments");
        }
    }
}

void RPN::do_op()
{
    int first, second;

    for (size_t i = 0; i < this->_argument.length(); i++)
    {
        if (std::isdigit(this->_argument[i]))
            this->_stack.push(this->_argument[i] - 48);
        else if (!std::isspace(this->_argument[i]))
        {
            if (this->_stack.empty())
                throw std::runtime_error("no proper arguments");
            else
            {
                second = this->_stack.top();
                this->_stack.pop();
                if (this->_stack.empty())
                    throw std::runtime_error("no proper arguments");
                first = this->_stack.top();
                this->_stack.pop();
                this->_stack.push(operate(first, second, this->_argument[i]));
            }
        }
    }
    std::cout << this->_stack.top() << std::endl;
    this->_stack.pop();
    if (!this->_stack.empty())
        throw std::runtime_error("wrong count of operations or numbers");
}

void RPN::calculate(char **args)
{
    this->parse(args);
    this->do_op();
}