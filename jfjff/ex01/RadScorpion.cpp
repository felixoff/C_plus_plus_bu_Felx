#include "RadScorpion.hpp"

RadScorpion::RadScorpion(const RadScorpion &other):Enemy(other.hp,other.type)
{
}

RadScorpion::RadScorpion():Enemy(80, "RadScorpion")
{
    std::cout << "* click click click *" << std::endl;
}

RadScorpion &RadScorpion::operator =(const RadScorpion &other)
{
    this->hp = other.hp;
    this->type = other.type;
    return *this;
}

RadScorpion:: ~RadScorpion()
{
    std::cout <<   "* SPROTCH *" << std::endl;
}

void RadScorpion::takeDamage(int damage)
{
    Enemy::takeDamage(damage);
}