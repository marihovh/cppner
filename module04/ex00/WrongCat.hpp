#pragma once
#include "./WrongAnimal.hpp"

class WrongCat:public WrongAnimal
{
    public:
        WrongCat();
        ~WrongCat();
        WrongCat(const WrongCat& copik);
        WrongCat& operator= (const WrongCat& other);
        void makeSound() const;
};