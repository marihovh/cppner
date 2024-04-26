#pragma once
#include "./AbsAnimal.hpp"

class Cat:public AbsAnimal
{
    public:
        Cat();
        ~Cat();
        Cat(const Cat& copik);
        Cat& operator= (const Cat& other);
        void makeSound() const;
};