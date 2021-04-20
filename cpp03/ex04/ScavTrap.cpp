#include "ScavTrap.hpp"

std::string chalenges[5] = {" Try to beat me, bastard", " I stop you bastard!", " Lets start the party"," Who create me?", " Be my friend"};

ScavTrap::ScavTrap()
{
    this->hit_points = 100;
    this->max_hit_points = 100;
    this->energy_points = 50; 
    this->max_energy_points = 50;
    this->level = 1;
    this->melee_attack_damage = 20; 
    this->ranged_attack_damage = 15;
    this->armor_damage_reduction = 3;
    std::cout << this->name << " : You shall not path!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
    this->name = other.name;
    ClapTrap::copy(other);
    std::cout << " Togeter we are a force" << std::endl;
}

ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
    this->hit_points = 100;
    this->max_hit_points = 100;
    this->energy_points = 50; 
    this->max_energy_points = 50;
    this->level = 1;
    this->melee_attack_damage = 20; 
    this->ranged_attack_damage = 15;
    this->armor_damage_reduction = 3;
    std::cout << this->name << " : Again Your shall not path!" << std::endl;
}


ScavTrap::~ScavTrap()
{
    std::cout << this->name << " go ahead...You win" << std::endl;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &other)
{
    this->name = other.name;
    std::cout << "Hi brother!" << std::endl;
    return *this;
}

void ScavTrap::rangedAttack(std::string const & target)
{
    std::cout << "ScavTrap" << this->name <<" ranged attacks " << target << \
" at range, causing " << this->ranged_attack_damage << \
    " points of damage!" << std::endl;
}

void ScavTrap::meleeAttack(std::string const & target)
{
    std::cout << "ScavTrap" << this->name <<" melee attacks " << target << \
    " at range, causing " << this->melee_attack_damage << \
    " points of damage!" << std::endl;
}

void ScavTrap::challengeNewcomer()
{
    std::cout<< this->name << ":" <<chalenges[rand() % 5] << std::endl;
}
