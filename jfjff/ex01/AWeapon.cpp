#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const & name, int apcost, int damage):name(name),apcost(apcost),damage(damage)
{

}

AWeapon::AWeapon(const AWeapon &other):name(other.name),apcost(other.apcost),damage(other.damage)
{
}

AWeapon &AWeapon::operator =(const AWeapon &other)
{
    this->name = other.name;
    this->damage = other.damage;
    this->apcost = other.apcost;
    return *this;
}

AWeapon:: ~AWeapon()
{
}

std::string const AWeapon::getName() const
{
    return this->name;
}

int AWeapon::getAPCost() const
{
    return this->apcost;
}

int AWeapon::getDamage() const
{
    return this->damage;
}