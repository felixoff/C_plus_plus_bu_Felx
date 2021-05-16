#ifndef ICE_H
#define ICE_H
#include"AMateria.hpp"
#include <iostream>
class Ice:public AMateria
{
public:
Ice();
Ice(Ice const &other);
Ice &operator =(Ice const &other);
virtual ~Ice();
virtual AMateria* clone() const;
virtual void use(ICharacter& target);
};

#endif