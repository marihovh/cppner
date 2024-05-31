#include "./iter.hpp"


int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    iter(arr, 5, pr<int>);
    return 0;
}