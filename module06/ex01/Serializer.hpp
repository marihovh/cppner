#pragma once
#include <iostream>
#include <cstdint>

struct Data
{
    int data;
};

class Serializer
{
    public:
        Serializer();
        ~Serializer();
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};