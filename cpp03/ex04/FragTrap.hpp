#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
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
