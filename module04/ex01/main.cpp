#include "./Animal.hpp"
#include "./Cat.hpp"
#include "./Dog.hpp"
#include "./Brain.hpp"

int main()
{
    Animal **meta = new Animal*[10];
    for (int i = 0; i < 10; i++)
    {
        if (i < 5)
            meta[i] = new Cat();
        else
            meta[i] = new Dog();
    }
    for (int i = 0; i < 10; i++)
    {
        meta[i]->makeSound();
        delete meta[i];
    }
    delete [] meta;
    return 0;
}