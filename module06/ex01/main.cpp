#include "./Serializer.hpp"

int main()
{
    Data dat;
    dat.data = 9;
    Serializer bo;
    Data* ye = &dat;
    uintptr_t intPtr = bo.serialize(ye);
    std::cout << intPtr << std::endl;
    std::cout << bo.deserialize(intPtr) << std::endl;
    return 0;
}