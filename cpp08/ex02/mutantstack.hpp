#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include<iostream>
#include<deque>
#include<stack>
#include<vector>
template<typename T>//, typename Container = std::vector<T>>
class MutantStack:public std::stack<T>//, Container>
{
    public:
    MutantStack();
    MutantStack(MutantStack const &other);
     ~MutantStack();
    MutantStack &operator=(MutantStack const &other);
  //  using std::stack<T, Container>::c;
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
};

template<typename T>
MutantStack<T>::MutantStack():std::stack<T>()
{
}
template<typename T>
MutantStack<T>::MutantStack(MutantStack const &other):std::stack<T>(other)
    {
    }

template<typename T>
MutantStack<T>::~MutantStack(){}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &other)
{
    this->c = other.c;
   return *this;
}

    template<typename T>
    typename MutantStack<T>::iterator MutantStack<T>::begin()
    {
        return this->c.begin();
    }
    template<typename T>
    typename MutantStack<T>::iterator MutantStack<T>::end()
    {
        return this->c.end();
    }
    template<typename T>
    typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
    {
        return this->c.begin();
    }
    template<typename T>
    typename MutantStack<T>::const_iterator MutantStack<T>::end() const
    {
        return this->c.end();
    }

#endif