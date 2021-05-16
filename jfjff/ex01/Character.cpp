#include "Character.hpp"
AWeapon *Character::getWeapon()
{
    return this->weapon;
}

int Character::getAPcount() const
{
    return this->apcount;
}

Character::Character(std::string const & name):name(name),apcount(40),weapon(NULL)
{
}

Character::Character(const Character &other):name(other.name),apcount(other.apcount),weapon(other.weapon)
{
}

Character &Character::operator =(const Character &other)
{
    this->apcount = other.apcount;
    this->name = other.name;
    this->weapon = other.weapon;
    return *this;
}

Character:: ~Character()
{
}

void Character::recoverAP()
{
    if (this->apcount + 10 >= 40)
        this->apcount = 40;
    else
        this->apcount = this->apcount + 10;
}

std::string const Character::getName() const
{
    return this->name;
}

void Character::equip(AWeapon* weapon)
{
    this->weapon = weapon;
}

void Character::attack(Enemy* enemy)
{
    std::cout <<  this->getName() << " attacks " <<enemy->getType() << " with a " << this->getWeapon()->getName() << std::endl;
    if (this->getWeapon() == NULL || enemy == NULL)
        return;
    if (this->apcount < this->getWeapon()->getAPCost())
        return;
    this->apcount = this->apcount - this->getWeapon()->getAPCost();
    this->getWeapon()->attack();
    enemy->takeDamage(this->getWeapon()->getDamage());
    if (enemy->getHP() <= 0)
       delete enemy;
}

std::ostream &operator <<(std::ostream &output, Character &other)
{
    if (other.getWeapon() != NULL)
        std::cout <<  other.getName() << " has " << other.getAPcount() << \
        " AP and wields a " << other.getWeapon()->getName()<< std::endl;
    else
        std::cout << other.getName() <<" has " << other.getAPcount() << \
        " AP and is unarmed"<<std::endl;
    return output;
}