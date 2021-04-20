#include "SuperTrap.hpp"

SuperTrap::SuperTrap()
{
    this->hit_points = this->FragTrap::hit_points;
    this->max_hit_points = FragTrap::max_hit_points;
    this->energy_points = this->NinjaTrap::energy_points;; 
    this->max_energy_points = this->NinjaTrap::max_energy_points;
    this->level = 1;
    this->melee_attack_damage = this->NinjaTrap::melee_attack_damage;
    this->ranged_attack_damage = this->FragTrap::ranged_attack_damage;
    this->armor_damage_reduction = this->FragTrap::armor_damage_reduction;
    std::cout << this->name << " : I'm noname super class" << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap &other):ClapTrap(other.name),FragTrap(other.name),NinjaTrap(other.name)
{
    ClapTrap::copy(other);
    std::cout << this->name << " : I'm copy super class" << std::endl;
}

SuperTrap::SuperTrap(std::string name):ClapTrap(name), FragTrap(name), NinjaTrap(name)
{
    this->hit_points = this->FragTrap::hit_points;
    this->max_hit_points = FragTrap::max_hit_points;
    this->energy_points = this->NinjaTrap::energy_points;; 
    this->max_energy_points = this->NinjaTrap::max_energy_points;
    this->level = 1;
    this->melee_attack_damage = this->NinjaTrap::melee_attack_damage;
    this->ranged_attack_damage = this->FragTrap::ranged_attack_damage;
    this->armor_damage_reduction = this->FragTrap::armor_damage_reduction;
    std::cout << this->name << " : I' named super class" << std::endl;
}

SuperTrap::~SuperTrap()
{
    std::cout << this->name << " I'm dyed super class" << std::endl;
}

SuperTrap &SuperTrap::operator = (const SuperTrap &other)
{
    ClapTrap::copy(other);
    std::cout << "i'm equal super class" << std::endl;
    return *this;
}


void SuperTrap::rangedAttack(std::string const & target)
{
    FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack(std::string const & target)
{
    NinjaTrap::rangedAttack(target);
}