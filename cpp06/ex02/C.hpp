#ifndef C_H
#define C_H

#include "Base.hpp"

class C:public Base
{
    public:
       C();
       ~C();
       C(C const &other);
       C &operator =(C const &other);
};

#endif