#ifndef AMATERIA_H
#define AMATERIA_H

class AMateria;
#include"ICharacter.hpp"
#include <iostream>

class AMateria
{
protected:
std::string type;
unsigned int _xp;
private:
AMateria();
public:
AMateria(std::string const & type);
AMateria(AMateria const &other);
AMateria &operator =(AMateria const &other);
virtual ~AMateria();
std::string const & getType() const; 
unsigned int getXP() const; 
virtual AMateria* clone() const = 0;
virtual void use(ICharacter& target);
};
#endif