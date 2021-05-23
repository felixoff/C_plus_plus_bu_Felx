#include<iostream>

template<typename T>
void strangeIter(T *mas, int lenght, void (*func)(T &));

template<typename T>
void mimic_cout(T &elem);