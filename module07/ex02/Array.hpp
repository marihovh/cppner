#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>

class Array
{
    private:
        T* arr;
        unsigned int len;
    public:
        Array();
        ~Array();
        Array(long int n);
        Array(const Array& copik);
        Array& operator= (const Array& other);
        T& operator[] (std::size_t idx);
        unsigned int size() const;
};


#include "Array.tpp"