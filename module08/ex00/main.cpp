#include "./easyfind.hpp"
#include <vector>

int main()
{
    try
    {
        std::vector<int> myVector;
        myVector.push_back(1);
        myVector.push_back(2);
        myVector.push_back(3);
        myVector.push_back(4);
        std::cout << *easyfind<std::vector<int> >(myVector, 30) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}