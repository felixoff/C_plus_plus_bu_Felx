#include<iostream>
template<typename T>
void strangeIter(T *mas, int lenght, void (*func)(T &))
{
    for (int i = 0; i < lenght; i++)
    {
        (*func)(mas[i]);
    }
}
template<typename T>
void mimic_cout(T &elem)
{
    std::cout <<elem <<std::endl;
}

int main()
{
    int lenght = 5;
    char mas[] = "abcdeif";
    int ints[] = {1,2,3,4,5};
    strangeIter<char>(mas,lenght,mimic_cout<char>);
    std::cout <<std::endl;
    strangeIter<int>(ints,lenght,mimic_cout<int>);
    return 0;
}