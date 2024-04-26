#pragma once
#include "./AAnimal.hpp"

class Dog:public AAnimal
{
    public:
        Dog();
        ~Dog();
        Dog(const Dog& copik);
        Dog& operator= (const Dog& other);
        void makeSound() const;
};