#include "NinjaTrap.hpp"


NinjaTrap::NinjaTrap()
{
    this->hit_points = 60;
    this->max_hit_points = 60;
    this->energy_points = 120; 
    this->max_energy_points = 120;
    this->level = 1;
    this->melee_attack_damage = 60; 
    this->ranged_attack_damage = 5;
    this->armor_damage_reduction = 0;
    std::cout << this->name << " : I beat samurai" << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap &other):ClapTrap(other.name)
{
    ClapTrap::copy(other);
    std::cout << " Now we command Ninjas" << std::endl;
}

NinjaTrap::NinjaTrap(std::string name):ClapTrap(name)
{
    this->hit_points = 60;
    this->max_hit_points = 60;
    this->energy_points = 120; 
    this->max_energy_points = 120;
    this->level = 1;
    this->melee_attack_damage = 60; 
    this->ranged_attack_damage = 5;
    this->armor_damage_reduction = 0;
    std::cout << this->name << " : double ninjas" << std::endl;
}

NinjaTrap::~NinjaTrap()
{
    std::cout << this->name << " Ninja sepuko" << std::endl;
}

NinjaTrap &NinjaTrap::operator = (const NinjaTrap &other)
{
    this->name = other.name;
    std::cout << "Copy ninja" << std::endl;
    return *this;
}

void NinjaTrap::ninjaShoebox(FragTrap &trap)
{
    trap.vaulthunter_dot_exe("Samurai");
}

void NinjaTrap::ninjaShoebox(ScavTrap &trap)
{
    trap.challengeNewcomer();
}

void NinjaTrap::ninjaShoebox(ClapTrap &trap)
{
    trap.meleeAttack("Samurai");
}

void NinjaTrap::ninjaShoebox(NinjaTrap &trap)
{
    trap.rangedAttack("Samurai");
}

void NinjaTrap::rangedAttack(std::string const & target)
{
    std::cout << "NinjaTrap" << this->name <<" ranged attacks " << target << \
" at range, causing " << this->ranged_attack_damage << \
    " points of damage!" << std::endl;
}

void NinjaTrap::meleeAttack(std::string const & target)
{
    std::cout << "NinjaTrap" << this->name <<" melee attacks " << target << \
    " at range, causing " << this->melee_attack_damage << \
    " points of damage!" << std::endl;
}