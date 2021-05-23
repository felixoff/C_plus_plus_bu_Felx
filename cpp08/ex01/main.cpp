#include "span.hpp"
int main()
{
Span sp = Span(23000);
sp.addNumber(5);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
std::multiset<int> multi_pulti_set;
for (int i = 20; i < 10020; i++)
    multi_pulti_set.insert(i);
std::multiset<int>::iterator start = multi_pulti_set.begin();
std::multiset<int>::iterator end = multi_pulti_set.end();
sp.addNumber(start,end);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
}