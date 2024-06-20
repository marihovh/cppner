#pragma once
#include <iostream>
#include <string>
#include <deque>
#include <cstring>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <list>

class PmergeMe
{
    public:
        PmergeMe(std::string& nums);
        ~PmergeMe();
        void parseList();
        void parseDeque();
        void mergeInsertList();
        void mergeInsertDeque();
        std::list<int> _list;
        std::deque<int> _nums;
    private:
        PmergeMe();
        void fillList();
        void fillDeque();
        void parse();
        void insertDequeSort(std::deque<int> greatest);
        void insertListSort(std::list<int> greatest);
        std::string _sequence; 
};

void printList(std::list<int> arg);
void printDeque(std::deque<int> arg);