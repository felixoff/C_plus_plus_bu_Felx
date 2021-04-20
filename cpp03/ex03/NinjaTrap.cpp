#include "NinjaTrap.hpp"


NinjaTrap::NinjaTrap():hit_points(60),max_hit_points(60),energy_points(120),max_energy_points(120),level(1),melee_attack_damage(60),ranged_attack_damage(5),armor_damage_reduction(0)
{
    this->name = "Anon Ninja";
        std::cout << this->name << " : I beat samurai" << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap &other)
{
    this->hit_points = other.hit_points;
    this->max_hit_points = other.max_hit_points;
    this->energy_points = other.energy_points;
    this->max_energy_points = other.max_energy_points;
    this->level = other.level;
    this->name = other.name;
    this->melee_attack_damage = other.melee_attack_damage;
    this->ranged_attack_damage = other.ranged_attack_damage;
    this->armor_damage_reduction= other.armor_damage_reduction;
    std::cout << " Now we command Ninjas" << std::endl;
}

NinjaTrap::NinjaTrap(std::string name):hit_points(60),max_hit_points(60),energy_points(120),max_energy_points(120),level(1),melee_attack_damage(60),ranged_attack_damage(5),armor_damage_reduction(0)
{
    this->name = name;
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