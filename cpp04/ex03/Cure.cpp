#include"Cure.hpp"


Cure::Cure(Cure const &other):AMateria(other.type)
{  
}

Cure &Cure::operator =(Cure const &other)
{
    this->type = other.type;
    this->_xp = other._xp;
    return(*this);
}

Cure::Cure():AMateria("cure")
{
}

Cure::~Cure()
{
}

void Cure::use(ICharacter& target)
{
    std::cout <<"* heals NAME’s wounds *"<< target.getName() <<" *" <<std::endl;
    AMateria::use(target);
}

AMateria *Cure::clone() const
{
    AMateria *mater = new Cure();
    return (mater);
}
