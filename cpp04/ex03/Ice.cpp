#include"Ice.hpp"

Ice::Ice(Ice const &other):AMateria(other.type)
{  
}

Ice &Ice::operator =(Ice const &other)
{
    this->type = other.type;
    this->_xp = other._xp;
    return(*this);
}

Ice::Ice():AMateria("ice")
{
}

Ice::~Ice()
{
}

void Ice::use(ICharacter& target)
{
    std::cout <<"* shoots an ice bolt at "<< target.getName() <<" *" <<std::endl;
    AMateria::use(target);
}

AMateria *Ice::clone() const
{
    AMateria *mater = new Ice();
    return (mater);
}
