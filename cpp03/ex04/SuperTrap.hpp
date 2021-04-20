#include "NinjaTrap.hpp"

class SuperTrap: public FragTrap, public NinjaTrap
{
    public:
        SuperTrap();
        SuperTrap(std::string name);
        SuperTrap(const SuperTrap &other);
        virtual ~SuperTrap();
        SuperTrap &operator =(const SuperTrap &other);
        virtual void rangedAttack(std::string const & target);
        virtual void meleeAttack(std::string const & target);
};