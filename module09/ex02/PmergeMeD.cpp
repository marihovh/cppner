#include "./PmergeMe.hpp"

void printDeque(std::deque<int> arg)
{
    std::deque<int>::iterator bb1;

    for (bb1 = arg.begin(); bb1 != arg.end(); ++bb1)
    {
        std::cout << *bb1 << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::insertDequeSort(std::deque<int> greatest)
{
    std::deque<int>::iterator it = this->_nums.begin();
    std::deque<int>::iterator begGreat = greatest.begin();
    while (begGreat != greatest.end())
    {
        if (it == this->_nums.end() || *begGreat < *it)
        {
            this->_nums.insert(it, *begGreat);
            begGreat = greatest.erase(begGreat); // Use erase to remove and get next iterator
        }
        else
            ++it;
    }
}

void PmergeMe::fillDeque()
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
        this->_nums.push_back(num);
    }
}

void PmergeMe::mergeInsertDeque()
{
    std::deque<int>::iterator it = this->_nums.begin();
    std::deque<int> greatest;

    if (this->_nums.size() % 2 != 0)
    {
        greatest.push_back(*it);
        it = this->_nums.erase(it);
    }
    while (it != this->_nums.end())
    {
        std::deque<int>::iterator next = std::next(it);
        if (next == this->_nums.end())
            break;
        if (*it > *next)
        {
            greatest.push_back(*it);
            it = this->_nums.erase(it);
        }
        else
        {
            greatest.push_back(*next);
            it = this->_nums.erase(next);
        }
        if (it == this->_nums.end())
            break;
    }
    std::sort(this->_nums.begin(), this->_nums.end());
    std::sort(greatest.begin(), greatest.end());
    this->insertDequeSort(greatest);
}

void PmergeMe::parseDeque()
{
    this->parse();
    this->fillDeque();
}