#pragma once
#include "./Brain.hpp"
#include <iostream>

class AbsAnimal
{
    protected:
        std::string type;
        Brain *brain;

    public:
        AbsAnimal();
        virtual ~AbsAnimal();
        AbsAnimal(const AbsAnimal& copik);
        AbsAnimal& operator= (const AbsAnimal& other);
        void setType(std::string tipik);
        std::string getType()  const;
    public:
        virtual void makeSound()  const = 0;
};