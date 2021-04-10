#include<iostream>

class ClapTrap
{
    private:
        int hit_points = 10;
        int max_hit_points = 10;
        int energy_points = 5; 
        int max_energy_points = 5;
        int level = 0;
        std::string name;
        int melee_attack_damage = 2; 
        int ranged_attack_damage = 1;
        int armor_damage_reduction = 0;
    public:
        ClapTrap(); 
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &other);
        virtual ~ClapTrap();
        ClapTrap &operator =(const ClapTrap &other);
        virtual void rangedAttack(std::string const & target);
        virtual void meleeAttack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void recoverEnergy(unsigned int amount);
};

ClapTrap::ClapTrap()
{
    this->name = "NONAME";
        std::cout << this->name << " : I'm your father" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    this->hit_points = other.hit_points;
    this->max_hit_points = other.max_hit_points;
    this->energy_points = other.energy_points;
    this->max_energy_points = other.max_energy_points;
    this->level = other.level;
    this->name = other.name;
    this->melee_attack_damage = other.melee_attack_damage;
    this->ranged_attack_damage = other.ranged_attack_damage;
    this->armor_damage_reduction= other.armor_damage_reduction;
    std::cout << " Now we Claps Traps" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    std::cout << this->name << " : my clone" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << this->name << " I crying and dying" << std::endl;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &other)
{
    this->name = other.name;
    std::cout << "Double Claple" << std::endl;
    return *this;
}

void ClapTrap::rangedAttack(std::string const & target)
{
    std::cout << "ClapTrap" << this->name <<" ranged attacks " << target << \
" at range, causing " << this->ranged_attack_damage << \
    " points of damage!" << std::endl;
}

void ClapTrap::meleeAttack(std::string const & target)
{
    std::cout << "ClapTrap" << this->name <<" melee attacks " << target << \
    " at range, causing " << this->melee_attack_damage << \
    " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount-this->armor_damage_reduction >= this->hit_points)
    {
        this->hit_points = 0;
        std::cout << this->name << " : end" << std::endl;
    }
    else if (this->armor_damage_reduction >= amount)
    {
        std::cout << this->name << " : no damage" << std::endl;
    }
    else 
    {
        std::cout << this->name << " : damaged" << std::endl;
        this->hit_points = this->hit_points + \
        this->armor_damage_reduction - amount;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (amount+this->hit_points >= this->max_hit_points)
    {
        this->hit_points = this->max_hit_points;
        std::cout << this->name << " : full repaired" << std::endl;
    }
    else 
    {
        std::cout << this->name << " : not full repaired" << std::endl;
        this->hit_points = this->hit_points + amount;
    }
}

void ClapTrap::recoverEnergy(unsigned int amount)
{
    if (amount+this->energy_points >= this->max_energy_points)
    {
        this->energy_points = this->max_energy_points;
        std::cout << this->name << " : have full energy" << std::endl;
    }
    else 
    {
        std::cout << this->name<< " : have not full energy" << std::endl;
        this->energy_points = this->energy_points + amount;
    }
}

class ScavTrap: public ClapTrap
{
    private:
        int hit_points = 100;
        int max_hit_points = 100;
        int energy_points = 50; 
        int max_energy_points = 50;
        int level = 1;
        std::string name;
        int melee_attack_damage = 20; 
        int ranged_attack_damage = 15;
        int armor_damage_reduction = 3;
        std::string chalenges[5] = {" Try to beat me, bastard"
        , " I stop you bastard!", " Lets start the party"," Who create me?", " Be my friend"};
    public:
        ScavTrap(); 
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &other);
        virtual ~ScavTrap();
        ScavTrap &operator =(const ScavTrap &other);
        void rangedAttack(std::string const & target) override;
        void meleeAttack(std::string const & target) override;
        void challengeNewcomer(void);
};

ScavTrap::ScavTrap()
{
    this->name = "Unonim";
        std::cout << this->name << " : You shall not path!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
    this->hit_points = other.hit_points;
    this->max_hit_points = other.max_hit_points;
    this->energy_points = other.energy_points;
    this->max_energy_points = other.max_energy_points;
    this->level = other.level;
    this->name = other.name;
    this->melee_attack_damage = other.melee_attack_damage;
    this->ranged_attack_damage = other.ranged_attack_damage;
    this->armor_damage_reduction= other.armor_damage_reduction;
    std::cout << " Togeter we are a force" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    this->name = name;
    std::cout << this->name << " : Again Your shall not path!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << this->name << " go ahead...You win" << std::endl;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &other)
{
    this->name = other.name;
    std::cout << "Hi brother!" << std::endl;
    return *this;
}

void ScavTrap::rangedAttack(std::string const & target)
{
    std::cout << "ScavTrap" << this->name <<" ranged attacks " << target << \
" at range, causing " << this->ranged_attack_damage << \
    " points of damage!" << std::endl;
}

void ScavTrap::meleeAttack(std::string const & target)
{
    std::cout << "ScavTrap" << this->name <<" melee attacks " << target << \
    " at range, causing " << this->melee_attack_damage << \
    " points of damage!" << std::endl;
}

void ScavTrap::challengeNewcomer()
{
    std::cout<< this->name << ":" <<this->chalenges[rand() % 5] << std::endl;
}

class FragTrap : public ClapTrap
{
    private:
        int hit_points = 100;
        int max_hit_points = 100;
        int energy_points = 100;
        int max_energy_points = 100;
        int level = 1;
        std::string name;
        int melee_attack_damage = 30;
        int ranged_attack_damage = 20;
        int armor_damage_reduction = 5;
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap &other);
        virtual ~FragTrap();
        FragTrap &operator =(const FragTrap &other);
        void rangedAttack(std::string const & target) override;
        void meleeAttack(std::string const & target) override;
        void vaulthunter_dot_exe(std::string const & target);
};

FragTrap::FragTrap()
{
    this->name = "Who am I?";
        std::cout << this->name << " : Time to play..." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
{
    this->hit_points = other.hit_points;
    this->max_hit_points = other.max_hit_points;
    this->energy_points = other.energy_points;
    this->max_energy_points = other.max_energy_points;
    this->level = other.level;
    this->name = other.name;
    this->melee_attack_damage = other.melee_attack_damage;
    this->ranged_attack_damage = other.ranged_attack_damage;
    this->armor_damage_reduction= other.armor_damage_reduction;
    std::cout << "We are legion! Go to pub)" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    this->name = name;
    std::cout << this->name << " : Time to play.." << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << this->name << " died" << std::endl;
}

FragTrap &FragTrap::operator = (const FragTrap &other)
{
    this->name = other.name;
    std::cout << "Peer to peer" << std::endl;
    return *this;
}

void FragTrap::rangedAttack(std::string const & target)
{
    std::cout << "FR4G-TP" << this->name <<" ranged attacks " << target << \
" at range, causing " << this->ranged_attack_damage << \
    " points of damage!" << std::endl;
}

void FragTrap::meleeAttack(std::string const & target)
{
    std::cout << "FR4G-TP" << this->name <<" melee attacks " << target << \
    "at range, causing " << this->melee_attack_damage << \
    " points of damage!" << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const & target)
{
    const char* quotes[5] = {"norm", "mouli", "err","-cheat", "leaks"};
    if (this->energy_points < 25)
    {
        std::cout << "I need more energy to do this" << std::endl;
    }
    else 
    {
        this->energy_points = this->energy_points - 25;
        std::cout<< quotes[rand() % 5] << ": 1 " << target << " : 0 (" << std::endl;
    }
}

class NinjaTrap: public ClapTrap
{
    private:
        int hit_points = 60;
        int max_hit_points = 60;
        int energy_points = 120; 
        int max_energy_points = 120;
        int level = 1;
        std::string name;
        int melee_attack_damage = 60; 
        int ranged_attack_damage = 5;
        int armor_damage_reduction = 0;
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

NinjaTrap::NinjaTrap()
{
    this->name = "Anon Ninja";
        std::cout << this->name << " : I beat samurai" << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap &other)
{
    this->hit_points = other.hit_points;
    this->max_hit_points = other.max_hit_points;
    this->energy_points = other.energy_points;
    this->max_energy_points = other.max_energy_points;
    this->level = other.level;
    this->name = other.name;
    this->melee_attack_damage = other.melee_attack_damage;
    this->ranged_attack_damage = other.ranged_attack_damage;
    this->armor_damage_reduction= other.armor_damage_reduction;
    std::cout << " Now we command Ninjas" << std::endl;
}

NinjaTrap::NinjaTrap(std::string name)
{
    this->name = name;
    std::cout << this->name << " : double ninjas" << std::endl;
}

NinjaTrap::~NinjaTrap()
{
    std::cout << this->name << " Ninja sepuko" << std::endl;
}

NinjaTrap &NinjaTrap::operator = (const NinjaTrap &other)
{
    this->name = other.name;
    std::cout << "Copy ninja" << std::endl;
    return *this;
}

void NinjaTrap::ninjaShoebox(FragTrap &trap)
{
    trap.vaulthunter_dot_exe("Samurai");
}

void NinjaTrap::ninjaShoebox(ScavTrap &trap)
{
    trap.challengeNewcomer();
}

void NinjaTrap::ninjaShoebox(ClapTrap &trap)
{
    trap.meleeAttack("Samurai");
}

void NinjaTrap::ninjaShoebox(NinjaTrap &trap)
{
    trap.rangedAttack("Samurai");
}

void NinjaTrap::rangedAttack(std::string const & target)
{
    std::cout << "NinjaTrap" << this->name <<" ranged attacks " << target << \
" at range, causing " << this->ranged_attack_damage << \
    " points of damage!" << std::endl;
}

void NinjaTrap::meleeAttack(std::string const & target)
{
    std::cout << "NinjaTrap" << this->name <<" melee attacks " << target << \
    " at range, causing " << this->melee_attack_damage << \
    " points of damage!" << std::endl;
}


int main( void )
{
    ClapTrap anonim1;
    ClapTrap notAnonim1("sjennett");
    ClapTrap clon1(notAnonim1);
    ClapTrap  peer1;
    peer1 = anonim1;

    ScavTrap anonim2;
    ScavTrap notAnonim2("sjennett");
    ScavTrap clon2(notAnonim2);
    ScavTrap  peer2;
    peer2 = anonim2;

    FragTrap anonim3;
    FragTrap notAnonim3("sjennett");
    FragTrap clon3(notAnonim3);
    FragTrap  peer3;
    peer3 = anonim3;

    NinjaTrap anonim4;
    NinjaTrap notAnonim4("sjennett");
    
    std::cout << std::endl;

    clon1.rangedAttack("droid");
    clon1.meleeAttack("someone");
    clon1.takeDamage(93);
    clon1.takeDamage(32);
    clon1.beRepaired(120);
    clon1.takeDamage(99);
    clon1.recoverEnergy(87);

    std::cout << std::endl;

    clon2.rangedAttack("droid");
    clon2.meleeAttack("someone");
    clon2.takeDamage(93);
    clon2.takeDamage(32);
    clon2.beRepaired(120);
    clon2.takeDamage(99);
    clon2.recoverEnergy(87);
    clon2.challengeNewcomer();
    clon2.challengeNewcomer();
    clon2.challengeNewcomer();
    peer2.challengeNewcomer();
    peer2.challengeNewcomer();
    
    std::cout << std::endl;
   
    clon3.rangedAttack("droid");
    clon3.meleeAttack("someone");
    clon3.takeDamage(93);
    clon3.takeDamage(32);
    clon3.beRepaired(120);
    clon3.takeDamage(99);
    clon3.vaulthunter_dot_exe("sjennett");
    clon3.vaulthunter_dot_exe("sjennett");
    clon3.vaulthunter_dot_exe("sjennett");
    clon3.vaulthunter_dot_exe("sjennett");
    clon3.vaulthunter_dot_exe("sjennett");
    clon3.recoverEnergy(87);
    clon3.vaulthunter_dot_exe("sjennett");
    clon3.vaulthunter_dot_exe("sjennett");
    
    std::cout << std::endl;

    notAnonim4.rangedAttack("droid");
    notAnonim4.meleeAttack("someone");
    notAnonim4.takeDamage(93);
    notAnonim4.takeDamage(32);
    notAnonim4.beRepaired(120);
    notAnonim4.takeDamage(99);
    notAnonim4.recoverEnergy(87);
    anonim4.ninjaShoebox(clon1);
    anonim4.ninjaShoebox(clon2);
    anonim4.ninjaShoebox(clon3);
    anonim4.ninjaShoebox(notAnonim4);
    std::cout << std::endl;
}