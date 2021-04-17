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
        const char *what() const noexcept;
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
        for (int i = 0; i < this->varsize; i++)
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
    for (int i = 0;i <this->varsize; i++)
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
    for (int i = 0; i < this->varsize; i++)
        varsize++;
    return varsize;
}


template <typename T>
const char *Array<T>::OutOfIndexException::what() const noexcept
{
    return "Index is out of array or mas is not exists";
}

int main(void)
{
    int *a =new int();
    std::cout << a << std::endl;

	Array<int>		array1(20);
    Array<int>      array2;
	std::cout << "First array size: " << array2.size() << std::endl;
	std::cout << "Empty array size: " << array1.size() << std::endl;


	array1[10] = 42;
	std::cout << "array1[10] : " << array1[10] << std::endl;
	array1[11] = 84;
	std::cout << "array1[11] : " << array1[11] << std::endl;
	
    Array<int>		array3(array1);
	array2 = array1;
	std::cout << "Copying array1 in array2..." << std::endl;
	array1[10] = 0;
	array1[11] = 0;

	std::cout << "array3[10] : " << array3[10] << std::endl;
	std::cout << "array3[11] : " << array3[11] << std::endl;

	std::cout << "array2[10] : " << array2[10] << std::endl;
	std::cout << "array2[11] : " << array2[11] << std::endl;

	std::cout << "Trying to set array1[30]" << std::endl;
	try {
		array1[30] = 42;
		std::cout << "SUCCESS, but was not expected !" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "ERROR (expected): " << e.what() << std::endl;
	}

	return (0);
}