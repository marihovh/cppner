#include "./Brain.hpp"

Brain::Brain()
{
}

Brain::~Brain()
{
}

Brain::Brain(const Brain& copik)
{
    *this = copik;
}

Brain& Brain::operator= (const Brain& other)
{
    if (this->ideas != other.ideas)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}