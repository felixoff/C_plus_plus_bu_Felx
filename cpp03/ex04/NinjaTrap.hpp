#include "ScavTrap.hpp"

class NinjaTrap: public virtual ClapTrap
{
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
