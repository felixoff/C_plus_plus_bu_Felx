#ifndef SPAN_H
#define SPAN_H

#include<iostream>
#include<exception>
#include <set>
#include<iterator>
#include<cmath>
#include <algorithm>

class Span
{
    private:
        std::multiset<int> mas;
        unsigned int size;
        Span();
    public:
        class MasIsFullException:std::exception
        {
            const char *what() const throw();
        };
        class CannotFindSpanException:std::exception
        {
            const char *what() const throw();
        };
        Span(unsigned int n);
        Span(Span const &other);
        ~Span();
        Span &operator =(Span const &other);
        void addNumber(int elem);
        void addNumber(std::multiset<int>::iterator start, std::multiset<int>::iterator end);
        unsigned int shortestSpan();
        unsigned int longestSpan();
};
#endif