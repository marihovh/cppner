#pragma once
#include "./AbsAnimal.hpp"

class Dog:public AbsAnimal
{
    public:
        Dog();
        ~Dog();
        Dog(const Dog& copik);
        Dog& operator= (const Dog& other);
        void makeSound() const;
};