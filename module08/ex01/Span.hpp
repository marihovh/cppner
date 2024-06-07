#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>

class MaxSizeReached: public std::exception
{
    const char* what() const throw()
    {
        return "ERROR: Maximum size of Span reached";
    }
};

class TooFewValue: public std::exception
{
    const char* what() const throw()
    {
        return "ERROR: Too few values to find a span";
    }
};

class Span
{
    public:
        Span(const unsigned int nb);
        ~Span();
        Span(const Span& copik);
        Span& operator=(const Span& other);
        void addNumber(const int nb);
        int shortestSpan();
        int longestSpan();
    private:
        Span();
        unsigned int _n;
        std::vector<int> _values;
};