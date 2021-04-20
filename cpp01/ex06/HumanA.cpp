#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):name(name),weapon(weapon)
{
    return;
}

HumanA::~HumanA()
{
    return;
}

void HumanA::attack()
{
    std::cout<<this->name << " attack by " << this->weapon.getType() <<std::endl;
}
