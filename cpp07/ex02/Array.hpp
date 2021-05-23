#include<iostream>
# include <exception>
template<typename T>
class Array
{
    private:
        unsigned int varsize;
        T *arr;
    public:
    class OutOfIndexException:public std::exception
    {
        const char *what() const throw();
    };
    Array();
    Array(unsigned int n);
    Array(Array const &other);
    ~Array();
    Array&operator=(Array const &other);
    T &operator[](unsigned int index);
    unsigned int size();
};
template <typename T>
Array<T>::Array():varsize(0),arr(NULL)
{
}

template <typename T>
Array<T>::Array(unsigned int n):varsize(n),arr(NULL)
{
    this->arr = new T[n];
}

template <typename T>
Array<T>::Array(Array const &other):varsize(0),arr(NULL)
{
    this->varsize = other.varsize;
    if (other.arr != NULL)
    {
        this->arr = new T[this->varsize];
        for (unsigned int i = 0; i < this->varsize; i++)
            this->arr[i] = other.arr[i];
    }
}

template <typename T>
Array<T>::~Array()
{
    if (this->arr != NULL)
        delete[] this->arr;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
    delete[] this->arr;
    this->arr = new T[other.varsize];
    this->varsize = other.varsize;
    for (unsigned int i = 0;i <this->varsize; i++)
        this->arr[i] = other.arr[i];
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if ((index > this->varsize - 1) || this->arr == NULL)
        throw OutOfIndexException();
    return this->arr[index];
}

template <typename T>
unsigned int Array<T>::size()
{
    unsigned int varsize = 0;
    for (unsigned int i = 0; i < this->varsize; i++)
        varsize++;
    return varsize;
}


template <typename T>
const char *Array<T>::OutOfIndexException::what() const throw()
{
    return "Index is out of array or mas is not exists";
}
