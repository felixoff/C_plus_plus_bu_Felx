#include<iostream>

class ClapTrap
{
    protected:
        unsigned int hit_points;
        unsigned int max_hit_points;
        unsigned int energy_points;
        unsigned int max_energy_points;
        unsigned int level;
        std::string name;
        unsigned int melee_attack_damage;
        unsigned int ranged_attack_damage;
        unsigned int armor_damage_reduction;
    public:
        ClapTrap(); 
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &other);
        virtual ~ClapTrap();
        ClapTrap &operator =(const ClapTrap &other);
        virtual void rangedAttack(std::string const & target);
        virtual void meleeAttack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void recoverEnergy(unsigned int amount);
        void copy(ClapTrap const &other);
};