#include "./PmergeMe.hpp"

void printList(std::list<int> arg)
{
    std::list<int>::iterator bb1;

    for (bb1 = arg.begin(); bb1 != arg.end(); ++bb1)
    {
        std::cout << *bb1 << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::insertListSort(std::list<int> greatest)
{
    std::list<int>::iterator it = this->_list.begin();
    std::list<int>::iterator begGreat = greatest.begin();

    while (begGreat != greatest.end())
    {
        if (it == this->_list.end() || *begGreat < *it)
        {
            this->_list.insert(it, *begGreat);
            begGreat = greatest.erase(begGreat);
        }
        else
            ++it;
    }
}

void PmergeMe::parse()
{
    for (size_t i = 0; i < this->_sequence.length(); i++)
    {
        if (!std::isdigit(this->_sequence[i]) && this->_sequence[i] != '+' && !std::isspace(this->_sequence[i]))
            throw std::runtime_error("no proper arguments");
        if (this->_sequence[i] == '+' && (!this->_sequence[i + 1] || !std::isdigit(this->_sequence[i + 1])))
            throw std::runtime_error("no proper arguments");
    }
}

void PmergeMe::fillList()
{
    int i = 0;
    while (i < (int)this->_sequence.length())
    {
        int j = i;
        while (this->_sequence[j] && std::isspace(this->_sequence[j]))
        {
            j++;
            i++;
        }
        if (j == (int)this->_sequence.length())
            throw std::runtime_error("empty");
        int k = j;
        while (this->_sequence[k] && !std::isspace(this->_sequence[k]))
        {
            k++;
            i++;
        }
        std::string tmp = this->_sequence.substr(j, k - j);
        long num = std::atol(tmp.c_str());
        if (num < INT_MIN || num > INT_MAX)
            throw std::runtime_error("sooo biiiggg numberss");
        this->_list.push_back(num);
    }
}

PmergeMe::PmergeMe(std::string &nums)
{
    this->_sequence = nums;
}

void PmergeMe::mergeInsertList()
{
    std::list<int>::iterator it = this->_list.begin();
    std::list<int>::iterator next = std::next(it);
    std::list<int> greatest;
    if (this->_list.size() % 2 != 0)
    {
        greatest.push_back(*it);
        it = this->_list.erase(it);
    }
    for (it = this->_list.begin(); it != this->_list.end(); it++)
    {
        next = std::next(it);
        if (it == this->_list.end())
            break;
        if (*it > *next)
        {
            greatest.push_back(*it);
            it = this->_list.erase(it);
        }
        else
        {
            greatest.push_back(*next);
            next = this->_list.erase(next);
        }
    }
    this->_list.sort();
    greatest.sort();
    this->insertListSort(greatest);
}

void PmergeMe::parseList()
{
    this->parse();
    this->fillList();
}

PmergeMe::~PmergeMe()
{
}