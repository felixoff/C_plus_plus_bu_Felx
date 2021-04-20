#include"span.hpp"

Span::Span():size(0)
{
}

Span::Span(unsigned int n):size(n)
{
}

Span::Span(Span const &other)
{
    this->size = other.size;
    this->mas.clear();
    this->mas = other.mas;
}

Span::~Span()
{
    this->mas.clear();
}

Span &Span::operator =(Span const &other)
{
    this->size = other.size;
    mas.clear();
    this->mas = other.mas;
    return *this;
}
        
void Span::addNumber(int elem)
{
 /*   int *tmp = new int[this->size];
    for (int i = 0; i < this->size; i++)
        tmp[i] = this.mas[i];
    delete[] this->mas;
    this->size = this->size + 1;
    this->mas = new int[this->size];
    for (int i = 0; i < this->size - 1; i++)
        this->mas[i] = tmp[i];
    this->mas[this->size - 1] = elem;*/

    if (this->mas.size() == this->size)
        throw(MasIsFullException());
    this->mas.insert(elem);
}

void Span::addNumber(std::multiset<int>::iterator start, std::multiset<int>::iterator end)
{
//    std::multiset<int>::iterator max = this->mas.end();
    if (this->mas.size()+ std::distance(start,end) >= this->size)
        throw(MasIsFullException());  
    while(start != end)
    {
        this->mas.insert(*start);
        start++;
    }
}

const char *Span::MasIsFullException::what() const throw()
{
    return "MasIsFullException";
}

const char *Span::CannotFindSpanException::what() const throw()
{
    return "CannotFindSpan";
}

unsigned int Span::shortestSpan()
{
    if (this->mas.size() < 2)
        throw(CannotFindSpanException());
   std::multiset<int>::iterator prev = this->mas.begin();
   std::multiset<int>::iterator next = ++this->mas.begin();
   unsigned int min_dist = std::abs(*next - *prev);
    prev++;
    next++;
   unsigned int dist;
   while(next != this->mas.end())
   {
        dist = std::abs(*next - *prev);
        if (dist < min_dist)
            min_dist = dist;
        prev++;
        next++;
   }
   return min_dist;
}

unsigned int Span::longestSpan()
{
    if (this->mas.size() < 2)
        throw(CannotFindSpanException());
    std::multiset<int>::iterator min_elem = std::min_element(this->mas.begin(),this->mas.end());
    std::multiset<int>::iterator max_elem = std::max_element(this->mas.begin(),this->mas.end());
    int min = *min_elem;
    int max = *max_elem;
    return std::abs(max-min);
}
