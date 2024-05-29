#pragma once
#include <iostream>

template <typename T>

void pr(T par)
{
    std::cout << par << std::endl;
}

template <typename T, typename F>

void iter(T* arr, int len, F foo)
{
    for (int i = 0; i < len; i++)
        foo(arr[i]);
}
