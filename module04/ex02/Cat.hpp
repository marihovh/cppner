#pragma once
#include "./AAnimal.hpp"

class Cat:public AAnimal
{
    public:
        Cat();
        ~Cat();
        Cat(const Cat& copik);
        Cat& operator= (const Cat& other);
        void makeSound() const;
};