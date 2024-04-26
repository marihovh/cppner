#pragma once
#include <iostream>

class Animal
{
    protected:
        std::string type;
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