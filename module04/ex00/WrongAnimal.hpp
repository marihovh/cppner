#pragma once
#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        virtual ~WrongAnimal();
        WrongAnimal(const WrongAnimal& copik);
        WrongAnimal& operator= (const WrongAnimal& other);
        void setType(std::string tipik);
        std::string getType()  const;
    public:
        void makeSound()  const;
};