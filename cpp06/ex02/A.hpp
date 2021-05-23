#ifndef A_H
#define A_H

#include "Base.hpp"

class A:public Base
{
    public:
        A();
        ~A();
        A(A const &other);
        A &operator =(A const &other);
};

#endif