#include "ClapTrap.hpp"

ClapTrap::ClapTrap():hit_points(10),max_hit_points(10),energy_points(5),max_energy_points(5),level(0),melee_attack_damage(2),ranged_attack_damage(1),armor_damage_reduction(0)
{
    this->name = "NONAME";
        std::cout << this->name << " : I'm your father" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
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
    std::cout << " Now we Claps Traps" << std::endl;
}

void ClapTrap::copy(ClapTrap const &other)
{
    this->hit_points = other.hit_points;
    this->max_hit_points = other.max_hit_points;
    this->energy_points = other.energy_points;
    this->max_energy_points = other.max_energy_points;
    this->level = other.level;
 //   this->name = other.name;
    this->melee_attack_damage = other.melee_attack_damage;
    this->ranged_attack_damage = other.ranged_attack_damage;
    this->armor_damage_reduction= other.armor_damage_reduction;    
}

ClapTrap::ClapTrap(std::string name):hit_points(10),max_hit_points(10),energy_points(5),max_energy_points(5),level(0),melee_attack_damage(2),ranged_attack_damage(1),armor_damage_reduction(0)
{
    this->name = name;
    std::cout << this->name << " : my clone" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << this->name << " I crying and dying" << std::endl;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &other)
{
    this->name = other.name;
    std::cout << "Double Claple" << std::endl;
    return *this;
}

void ClapTrap::rangedAttack(std::string const & target)
{
    std::cout << "ClapTrap" << this->name <<" ranged attacks " << target << \
" at range, causing " << this->ranged_attack_damage << \
    " points of damage!" << std::endl;
}

void ClapTrap::meleeAttack(std::string const & target)
{
    std::cout << "ClapTrap" << this->name <<" melee attacks " << target << \
    " at range, causing " << this->melee_attack_damage << \
    " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount-this->armor_damage_reduction >= this->hit_points)
    {
        this->hit_points = 0;
        std::cout << this->name << " : end" << std::endl;
    }
    else if (this->armor_damage_reduction >= amount)
    {
        std::cout << this->name << " : no damage" << std::endl;
    }
    else 
    {
        std::cout << this->name << " : damaged" << std::endl;
        this->hit_points = this->hit_points + \
        this->armor_damage_reduction - amount;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (amount+this->hit_points >= this->max_hit_points)
    {
        this->hit_points = this->max_hit_points;
        std::cout << this->name << " : full repaired" << std::endl;
    }
    else 
    {
        std::cout << this->name << " : not full repaired" << std::endl;
        this->hit_points = this->hit_points + amount;
    }
}

void ClapTrap::recoverEnergy(unsigned int amount)
{
    if (amount+this->energy_points >= this->max_energy_points)
    {
        this->energy_points = this->max_energy_points;
        std::cout << this->name << " : have full energy" << std::endl;
    }
    else 
    {
        std::cout << this->name<< " : have not full energy" << std::endl;
        this->energy_points = this->energy_points + amount;
    }
}
