#include "./Span.hpp"

Span::Span(const unsigned int nb)
{
    if (nb > this->_n)
        throw MaxSizeReached();
    this->_n = nb;
}

Span::~Span()
{
}

Span::Span(const Span& copik)
{
    *this = copik;
}

Span& Span::operator=(const Span& other)
{
    this->_n = other._n;
    this->_values = other._values;
    return *this;
}

void Span::addNumber(const int nb)
{
    if (this->_values.size() > this->_n)
        throw MaxSizeReached();
    this->_values.push_back(nb);
}

int Span::shortestSpan()
{
    if (this->_values.size() < 2)
        throw TooFewValue();
    std::vector<int> sorted = this->_values;
    std::sort(sorted.begin(), sorted.end());
    int min = INT_MAX;
    for (size_t i = 1; i < sorted.size(); ++i) {
        int difference = sorted[i] - sorted[i - 1];
        if (difference < min) {
            min = difference;
        }
    }
    return min;
}

int Span::longestSpan()
{
    if (this->_values.size() < 2)
        throw TooFewValue();
    std::vector<int>::iterator max = std::max_element(this->_values.begin(), this->_values.end());
    std::vector<int>::iterator min = std::min_element(this->_values.begin(), this->_values.end());
    return *max - *min;
}