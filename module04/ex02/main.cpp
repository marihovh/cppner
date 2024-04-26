#include "./Animal.hpp"
#include "./AbsAnimal.hpp"
#include "./Cat.hpp"
#include "./Dog.hpp"
#include "./Brain.hpp"

int main()
{
    Animal *animalss = new Animal();
    std::cout << animalss->getType();
    // AbsAnimal **meta = new AbsAnimal*[10];
    // for (int i = 0; i < 10; i++)
    // {
    //     if (i < 5)
    //         meta[i] = new Cat();
    //     else
    //         meta[i] = new Dog();
    // }
    // for (int i = 0; i < 10; i++)
    // {
    //     meta[i]->makeSound();
    // }
    // delete [] meta;
    return 0;
}