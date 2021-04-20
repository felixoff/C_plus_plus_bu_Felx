#include "HumanA.hpp"

class HumanB
{
    private:
        Weapon *weapon;
        std::string name;
    public:
        HumanB(std::string name);
        virtual ~HumanB();
        void setWeapon(Weapon &weapon);
        void attack();
};