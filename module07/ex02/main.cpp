#include "./Array.hpp"

int main()
{
    
    try
    { // maybe the arr is empty
        Array<int> arr(111);

        for (unsigned int i = 0; i < arr.size(); i++)
            arr[i] = i;
        for (unsigned int i = 0; i < arr.size(); i++)
            std::cout << "it is " << arr[i] << std::endl;
        Array<int> arr1 = arr;
        std::cout << arr1.size() << std::endl;

        arr1[0];
        
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}