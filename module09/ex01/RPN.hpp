#pragma once
#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <cstring>
#include <stdexcept>
#include <cstdlib>

class RPN
{
public:
    RPN();
    void calculate(char **argv);
    ~RPN();
private:
    std::stack<int> _stack;
    void parse(char **arg);
    void do_op();
    std::string _argument;
};