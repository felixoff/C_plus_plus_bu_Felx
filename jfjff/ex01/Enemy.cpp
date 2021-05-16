#include "Enemy.hpp"


Enemy::Enemy(int hp, std::string const & type):hp(hp),type(type)
{
}

Enemy::Enemy(const Enemy &other):hp(other.hp),type(other.type)
{
}

Enemy &Enemy::operator =(const Enemy &other)
{
    this->hp = other.hp;
    this->type = other.type;
    return *this;
}

Enemy:: ~Enemy()
{
}

std::string const Enemy::getType() const
{
    return this->type;
}

int Enemy::getHP() const
{
    return this->hp;
}

void Enemy::takeDamage(int damage)
{
    if (damage >= 0)
        this->hp = this->hp - damage;
}