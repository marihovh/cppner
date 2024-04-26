#pragma once
#include <iostream>
#include "./Brain.hpp"

class Animal
{
    protected:
        std::string type;
        Brain *brain;
    public:
        Animal();
        virtual ~Animal();
        Animal(const Animal& copik);
        Animal& operator= (const Animal& other);
        void setType(std::string tipik);
        std::string getType()  const;
    public:
        virtual void makeSound()  const;
};