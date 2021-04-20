#include "A.hpp"

A::A()
{
}

A::~A()
{
}

A::A(A const &other)
{
    (void)other;
}

A &A::operator =(A const &other)
{
    (void)other;
    return *this;
}
