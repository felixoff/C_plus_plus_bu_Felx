#include "FragTrap.hpp"


FragTrap::FragTrap()
{
    this->hit_points = 100;
    this->max_hit_points = 100;
    this->energy_points = 100;
    this->max_energy_points = 100;
    this->level = 1;
    this->melee_attack_damage = 30;
    this->ranged_attack_damage = 20;
    this->armor_damage_reduction = 5;
    std::cout << this->name << " : Time to play..." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other):ClapTrap(other.name)
{
    ClapTrap::copy(other);
    std::cout << "We are legion! Go to pub)" << std::endl;
}

FragTrap::FragTrap(std::string name):ClapTrap(name)
{
    this->hit_points = 100;
    this->max_hit_points = 100;
    this->energy_points = 100;
    this->max_energy_points = 100;
    this->level = 1;
    this->melee_attack_damage = 30;
    this->ranged_attack_damage = 20;
    this->armor_damage_reduction = 5;
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
