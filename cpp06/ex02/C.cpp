#include "C.hpp"

C::C()
{
}

C::~C()
{
}

C::C(C const &other)
{
    (void)other;
}

C &C::operator =(C const &other)
{
    (void)other;
    return *this;
}