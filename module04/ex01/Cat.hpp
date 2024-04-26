#pragma once
#include "./Animal.hpp"

class Cat:public Animal
{
    public:
        Cat();
        ~Cat();
        Cat(const Cat& copik);
        Cat& operator= (const Cat& other);
        void makeSound() const;
};