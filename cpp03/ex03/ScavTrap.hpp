#include "FragTrap.hpp"

class ScavTrap: public ClapTrap
{
    private:
         int hit_points;
         int max_hit_points;
         int energy_points;
         int max_energy_points;
         int level;
         std::string name;
         int melee_attack_damage;
         int ranged_attack_damage;
         int armor_damage_reduction;
    public:
        ScavTrap(); 
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &other);
        virtual ~ScavTrap();
        ScavTrap &operator =(const ScavTrap &other);
        void rangedAttack(std::string const & target) ;
        void meleeAttack(std::string const & target) ;
        void challengeNewcomer(void);
};

