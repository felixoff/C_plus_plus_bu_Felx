#include "PlasmaRifle.hpp"


PlasmaRifle::PlasmaRifle():AWeapon("Plasma Rifle",5,21)
{
}

PlasmaRifle::PlasmaRifle(const PlasmaRifle &other):AWeapon(other.name,other.apcost,other.damage)
{
}

PlasmaRifle &PlasmaRifle::operator =(const PlasmaRifle &other)
{
    this->name = other.name;
    this->damage = other.damage;
    this->apcost = other.apcost;
    return *this;
}

PlasmaRifle:: ~PlasmaRifle()
{
}

void PlasmaRifle::attack() const
{
    std::cout << "* piouuu piouuu piouuu *" << std::endl;;
}
