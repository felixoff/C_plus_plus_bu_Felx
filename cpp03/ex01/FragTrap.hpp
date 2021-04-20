#include <iostream>
class FragTrap
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
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap &other);
        virtual ~FragTrap();
        FragTrap &operator =(const FragTrap &other);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void recoverEnergy(unsigned int amount);
        void rangedAttack(std::string const & target) ;
        void meleeAttack(std::string const & target) ;
        void vaulthunter_dot_exe(std::string const & target);
};
