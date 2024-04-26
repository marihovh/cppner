#pragma once
#include <iostream>

class Brain
{
    protected:
        std::string ideas[100];
    public:
        Brain();
        ~Brain();
        Brain(const Brain& copik);
        Brain& operator= (const Brain& other);
};