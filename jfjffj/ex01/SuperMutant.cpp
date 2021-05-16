#include "SuperMutant.hpp"

SuperMutant::SuperMutant(const SuperMutant &other):Enemy(other.hp,other.type)
{
}

SuperMutant::SuperMutant():Enemy(170,"Super Mutant")
{
    std::cout <<  "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant &SuperMutant::operator =(const SuperMutant &other)
{
    this->hp = other.hp;
    this->type = other.type;
    return *this;
}

SuperMutant:: ~SuperMutant()
{
    std::cout <<  "Aaargh..." << std::endl;
}

void SuperMutant::takeDamage(int damage)
{
    Enemy::takeDamage(damage-3);
}