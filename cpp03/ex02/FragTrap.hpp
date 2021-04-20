#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
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
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap &other);
        virtual ~FragTrap();
        FragTrap &operator =(const FragTrap &other);
        void rangedAttack(std::string const & target) ;
        void meleeAttack(std::string const & target) ;
        void vaulthunter_dot_exe(std::string const & target);
};
