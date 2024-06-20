#include "./PmergeMe.hpp"
#include <sys/time.h>

int main(int argc, char* argv[])
{
    try
    {
        if (argc <= 1)
            throw std::runtime_error("too few arguments");
        std::string sequence = argv[1];
        for (int i = 1; argv[i + 1]; i++)
        {
            std::string tmp = argv[i + 1];
            sequence += " " + tmp;
        }
        PmergeMe sorterL = PmergeMe(sequence);
        PmergeMe sorterD = PmergeMe(sequence);
        // dequee
        sorterD.parseDeque();
        std::cout << "BEFORE: ";
        printDeque(sorterD._nums);
        struct timeval  time;
        gettimeofday(&time, NULL);
        long long   DequeBefore = time.tv_sec * 1000000LL + time.tv_usec; // in microseconds
        sorterD.mergeInsertDeque();
        gettimeofday(&time, NULL);
        long long   DequeAfter = time.tv_sec * 1000000LL + time.tv_usec; // in microseconds
        std::cout << "AFTER: ";
        printDeque(sorterD._nums);
        std::cout<< "Time to process a range of " << sorterD._nums.size() << "elements with std::deque: " << (DequeAfter - DequeBefore) / 1000.0 << " us\n";
        // listt
        sorterL.parseList();
        struct timeval  time1;
        gettimeofday(&time1, NULL);
        long long   ListBefore = time1.tv_sec * 1000000LL + time1.tv_usec;
        sorterL.mergeInsertList();
        gettimeofday(&time1, NULL);
        long long   ListAfter = time1.tv_sec * 1000000LL + time1.tv_usec; // in microseconds
        std::cout << "Time to process a range of " << sorterL._list.size() << " elements with std::list :" << (ListAfter - ListBefore) / 1000.0 << " us\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}