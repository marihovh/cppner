#pragma once
#include <iostream>
#include <stdexcept>

class NotFound: public std::exception
{
    const char* what() const throw()
    {
        return "ERROR: Element not found";
    }
};

template <typename Container>

typename Container::iterator easyfind(Container& arg, int nb)
{
    typename Container::iterator it = find(arg.begin(), arg.end(), nb);
    if (it == arg.end())
        throw NotFound();
    return (it);
}