#include<iostream>
template<typename T>
void swap(T &s1, T &s2);

template<typename T>
T &min(T &s1, T &s2);

template<typename T>
T &max(T &s1, T &s2);

template<typename T>
void swap(T &s1, T &s2)
{
    T tmp = s1;
    s1 = s2;
    s2 = tmp;
}

template<typename T>
T &min(T &s1, T &s2)
{
    if (s1 < s2)
        return s1;
    else
        return s2;
}

template<typename T>
T &max(T &s1, T &s2)
{
    if (s1 > s2)
        return s1;
    else
        return s2;
}

int main()
{
    int s1 = 4;
    int s2 = 5;
    double s3 = 4;
    double s4 = 5;
    int mini;
    double mind;
    double maxd;
    swap<int>(s1,s2);
    mini = min<int>(s1,s2);
    mind = min<double>(s3,s4);
    maxd = max<double>(s3,s4);

    std::cout<<"s1= "<< s1 << std::endl;
    std::cout<<"s2= "<< s2 << std::endl;
    std::cout<<"minint= "<< mini << std::endl;
    std::cout<<"mindouble= "<< mind << std::endl;
    std::cout<<"maxdouble= "<< maxd << std::endl;
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
}