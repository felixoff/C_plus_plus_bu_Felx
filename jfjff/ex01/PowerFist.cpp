#include "PowerFist.hpp"


PowerFist::PowerFist():AWeapon("Power Fist",8,50)
{
}

PowerFist::PowerFist(const PowerFist &other):AWeapon(other.name,other.apcost,other.damage)
{
}

PowerFist &PowerFist::operator =(const PowerFist &other)
{
    this->name = other.name;
    this->damage = other.damage;
    this->apcost = other.apcost;
    return *this;
}

PowerFist:: ~PowerFist()
{
}

void PowerFist::attack() const
{
    std::cout << "* pschhh... SBAM! *" << std::endl;
}

