#include "FragTrap.hpp"


FragTrap::FragTrap():hit_points(100),max_hit_points(100),energy_points(100),max_energy_points(100),level(1),melee_attack_damage(30),ranged_attack_damage(20),armor_damage_reduction(5)
{
    this->name = "Who am I?";
        std::cout << this->name << " : Time to play..." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
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
    std::cout << "We are legion! Go to pub)" << std::endl;
}

FragTrap::FragTrap(std::string name):hit_points(100),max_hit_points(100),energy_points(100),max_energy_points(100),level(1),melee_attack_damage(30),ranged_attack_damage(20),armor_damage_reduction(5)
{
    this->name = name;
    std::cout << this->name << " : Time to play.." << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << this->name << " died" << std::endl;
}

FragTrap &FragTrap::operator = (const FragTrap &other)
{
    this->name = other.name;
    std::cout << "Peer to peer" << std::endl;
    return *this;
}

void FragTrap::rangedAttack(std::string const & target)
{
    std::cout << "FR4G-TP" << this->name <<" ranged attacks " << target << \
" at range, causing " << this->ranged_attack_damage << \
    " points of damage!" << std::endl;
}

void FragTrap::meleeAttack(std::string const & target)
{
    std::cout << "FR4G-TP" << this->name <<" melee attacks " << target << \
    "at range, causing " << this->melee_attack_damage << \
    " points of damage!" << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const & target)
{
    const char* quotes[5] = {"norm", "mouli", "err","-cheat", "leaks"};
    if (this->energy_points < 25)
    {
        std::cout << "I need more energy to do this" << std::endl;
    }
    else 
    {
        this->energy_points = this->energy_points - 25;
        std::cout<< quotes[rand() % 5] << ": 1 " << target << " : 0 (" << std::endl;
    }
}

void FragTrap::takeDamage(unsigned int amount)
{
    if (amount-this->armor_damage_reduction >= this->hit_points)
    {
        this->hit_points = 0;
        std::cout << this->name << " : you kill me(" << std::endl;
    }
    else if (this->armor_damage_reduction >= amount)
    {
        std::cout << this->name << " : HAHAHA!You so weak" << std::endl;
    }
    else 
    {
        std::cout << this->name << " : HAHAHA!I am alive!!!!!" << std::endl;
        this->hit_points = this->hit_points + \
        this->armor_damage_reduction - amount;
    }
}

void FragTrap::beRepaired(unsigned int amount)
{
    if (amount+this->hit_points >= this->max_hit_points)
    {
        this->hit_points = this->max_hit_points;
        std::cout << this->name << " : you repair me!Thank you, Human" << std::endl;
    }
    else 
    {
        std::cout << this->name << " : give me more health)" << std::endl;
        this->hit_points = this->hit_points + amount;
    }
}

void FragTrap::recoverEnergy(unsigned int amount)
{
    if (amount+this->energy_points >= this->max_energy_points)
    {
        this->energy_points = this->max_energy_points;
        std::cout << this->name << " : I full of energy!Thank you, Human" << std::endl;
    }
    else 
    {
        std::cout << this->name<< " : give me more energy)" << std::endl;
        this->energy_points = this->energy_points + amount;
    }
}