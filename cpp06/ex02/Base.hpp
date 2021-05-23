#ifndef BASE_H
#define BASE_H

#include<iostream>

class Base
{
    public:
        virtual ~Base();
};

Base * generate(void);
void identify_from_pointer(Base * p);
void identify_from_reference( Base & p);

#endif