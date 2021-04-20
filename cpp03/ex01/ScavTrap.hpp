#include "FragTrap.hpp"

class ScavTrap
{
    private:
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
        ScavTrap(); 
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &other);
        virtual ~ScavTrap();
        ScavTrap &operator =(const ScavTrap &other);
        void rangedAttack(std::string const & target);
        void meleeAttack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void recoverEnergy(unsigned int amount);
        void challengeNewcomer(void);
};