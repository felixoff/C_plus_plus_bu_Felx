#include "HumanB.hpp"

Weapon::Weapon(std::string type)
{
    this->type = type;
}

Weapon::~Weapon()
{
    return;
}

std::string const & Weapon::getType()
{
    return this->type; 
}

void  Weapon::setType(std::string type)
{
    this->type = type; 
}