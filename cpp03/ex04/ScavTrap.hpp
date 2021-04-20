#include "FragTrap.hpp"

class ScavTrap: public virtual ClapTrap
{
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

