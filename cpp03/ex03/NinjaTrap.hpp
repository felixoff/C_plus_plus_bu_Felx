#include "ScavTrap.hpp"

class NinjaTrap: public ClapTrap
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
        NinjaTrap(); 
        NinjaTrap(std::string name);
        NinjaTrap(const NinjaTrap &other);
        virtual ~NinjaTrap();
        NinjaTrap &operator =(const NinjaTrap &other);
        virtual void rangedAttack(std::string const & target);
        virtual void meleeAttack(std::string const & target);
        void ninjaShoebox(FragTrap &trap);
        void ninjaShoebox(ScavTrap &trap);
        void ninjaShoebox(ClapTrap &trap);
        void ninjaShoebox(NinjaTrap &trap);
};
