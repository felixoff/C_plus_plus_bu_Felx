#include<iostream>
#include<sstream>

class Weapon
{
    private:
        std::string type;
    public:
        Weapon(std::string type);
        virtual ~Weapon();
        void setType(std::string type);
        std::string const &getType();
};

Weapon::Weapon(std::string type)
{
    this->type = type;
}

Weapon::~Weapon()
{
    return;
}

std::string const & Weapon::getType()
{
    return this->type; 
}

void  Weapon::setType(std::string type)
{
    this->type = type; 
}

class HumanA
{
    private:
        Weapon &weapon;
        std::string name;
    public:
        HumanA(std::string name, Weapon &weapon);
        virtual ~HumanA();
        void attack();
};
HumanA::HumanA(std::string name, Weapon &weapon):name(name),weapon(weapon)
{
    return;
}

HumanA::~HumanA()
{
    return;
}

void HumanA::attack()
{
    std::cout<<this->name << " attack by " << this->weapon.getType() <<std::endl;
}

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
HumanB::HumanB(std::string name)
{
    this->name = name;
}

HumanB::~HumanB()
{
    return;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack()
{
    std::cout<<this->name << " attack by " << this->weapon->getType() <<std::endl;
}
int main()
{
{
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
}
{
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
}
}