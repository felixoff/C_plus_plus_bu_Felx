#ifndef CURE_H
#define CURE_H
#include"AMateria.hpp"
#include <iostream>

class Cure:public AMateria
{
public:
Cure();
Cure(Cure const &other);
Cure &operator =(Cure const &other);
virtual ~Cure();
virtual AMateria* clone() const;
virtual void use(ICharacter& target);
};

#endif