#include "./Array.hpp"

template <typename T>

Array<T>::Array()
{
    this->arr = 0;
    this->len = 0;
}

template <typename T>

Array<T>::~Array()
{
    delete this->arr;
}

template <typename T>

Array<T>::Array(long int n)
{
    if (n < 0)
        throw std::logic_error("Error: the size can't be negative");
    this->len = n;
    this->arr = new T[n];
}

template <typename T>

Array<T>::Array(const Array &copik)
{
    int size = copik.size();
    this->arr = new T[size];

    for (int i = 0; i < size; i++)
        this->arr[i] = copik.arr[i];
    this->len = size;
}

template <typename T>

Array<T> &Array<T>::operator=(const Array &other)
{
    if (this != other)
    {
        this->~Array();
        int size = other.size();
        this->arr = new T[size];

        for (int i = 0; i < size; i++)
            this->arr[i] = other.arr[i];
        this->len = size;
    }
    return *this;
}

template <typename T>

T &Array<T>::operator[](std::size_t idx)
{
    if (idx < 0 || idx >= this->len)
        throw std::out_of_range("ERROR: index out of range");
    return this->arr[idx];
}

template <typename T>

unsigned int Array<T>::size() const
{
    return this->len;
}