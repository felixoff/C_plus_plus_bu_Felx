#include "Character.hpp"

Character::Character(std::string const &name):name(name)
{
    for (int i = 0; i < 4; i++)
        this->mater[i] = NULL;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        delete this->mater[i];
}

Character::Character(Character const &other):name(other.name)
{
    for (int i = 0; i < 4; i++)
        this->mater[i] = other.mater[i];
}

Character &Character::operator =(const Character &other)
{
    this->name = other.name;
    for (int i = 0; i < 4; i++)
        delete this->mater[i];
    for (int i = 0; i < 4; i++)
        this->mater[i] = other.mater[i];
    return *this;
}

std::string const & Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria* m)
{
    for (int i = 0;i < 4; i++)
    {
        if (m && this->mater[i] == NULL)
        {
            this->mater[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 4 || this->mater[idx]==NULL )
        return;
    this->mater[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 4 || this->mater[idx]==NULL )
        return;
    this->mater[idx]->use(target);
}