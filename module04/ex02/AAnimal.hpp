#pragma once
#include <iostream>
#include "./Brain.hpp"

class AAnimal
{
    protected:
        std::string type;
        Brain *brain;
    public:
        AAnimal();
        virtual ~AAnimal();
        AAnimal(const AAnimal& copik);
        AAnimal& operator= (const AAnimal& other);
        void setType(std::string tipik);
        std::string getType()  const;
    public:
        virtual void makeSound()  const = 0;
};