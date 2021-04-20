

#include"AMateria.hpp"

std::string const & AMateria::getType() const
{
    return this->type;
}

unsigned int AMateria::getXP() const
{
    return this->_xp;
}

AMateria::AMateria(std::string const & type):type(type),_xp(0)
{
}

AMateria::AMateria(AMateria const &other):type(other.type),_xp(other._xp)
{
}

AMateria &AMateria::operator =(AMateria const &other)
{
    this->type = other.type;
    this->_xp = other._xp;
    return(*this);
}

AMateria::~AMateria()
{
}

void AMateria::use(ICharacter& target)
{
    (void)target;
    this->_xp = this->_xp + 10;
}
