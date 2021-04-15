#include<iostream>

class ClapTrap
{
    protected:
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
        void copy(ClapTrap const &other);
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

ClapTrap::ClapTrap(const ClapTrap &other):name(other.name)
{
    ClapTrap::copy(other);
    std::cout << " Now we Claps Traps" << std::endl;
}

ClapTrap::ClapTrap(std::string name):name(name)
{
 //   this->name = name;
    std::cout << this->name << " : my clone" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << this->name << " I crying and dying" << std::endl;
}

void ClapTrap::copy(ClapTrap const &other)
{
    this->hit_points = other.hit_points;
    this->max_hit_points = other.max_hit_points;
    this->energy_points = other.energy_points;
    this->max_energy_points = other.max_energy_points;
    this->level = other.level;
 //   this->name = other.name;
    this->melee_attack_damage = other.melee_attack_damage;
    this->ranged_attack_damage = other.ranged_attack_damage;
    this->armor_damage_reduction= other.armor_damage_reduction;    
}

ClapTrap &ClapTrap::operator = (const ClapTrap &other)
{
    ClapTrap::copy(other);
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

class ScavTrap: public virtual ClapTrap
{
    public:
        ScavTrap(); 
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &other);
        virtual ~ScavTrap();
        ScavTrap &operator =(const ScavTrap &other);
        virtual void rangedAttack(std::string const & target) override;
        virtual void meleeAttack(std::string const & target) override;
        void challengeNewcomer(void);
};

std::string chalenges[5] = {" Try to beat me, bastard"
, " I stop you bastard!", " Lets start the party"," Who create me?", " Be my friend"};

ScavTrap::ScavTrap()
{
    this->hit_points = 100;
    this->max_hit_points = 100;
    this->energy_points = 50; 
    this->max_energy_points = 50;
    this->level = 1;
    this->melee_attack_damage = 20; 
    this->ranged_attack_damage = 15;
    this->armor_damage_reduction = 3;
    std::cout << this->name << " : You shall not path!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other):ScavTrap(other.name)
{
    ClapTrap::copy(other);
    std::cout << " Togeter we are a force" << std::endl;
}

ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
    this->hit_points = 100;
    this->max_hit_points = 100;
    this->energy_points = 50; 
    this->max_energy_points = 50;
    this->level = 1;
    this->melee_attack_damage = 20; 
    this->ranged_attack_damage = 15;
    this->armor_damage_reduction = 3;
    std::cout << this->name << " : Again Your shall not path!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << this->name << " go ahead...You win" << std::endl;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &other)
{
    ClapTrap::copy(other);
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
    std::cout<< this->name << ":" << chalenges[rand() % 5] << std::endl;
}

class FragTrap : public virtual ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap &other);
        virtual ~FragTrap();
        FragTrap &operator =(const FragTrap &other);
        virtual void rangedAttack(std::string const & target) override;
        virtual void meleeAttack(std::string const & target) override;
        void vaulthunter_dot_exe(std::string const & target);
};

FragTrap::FragTrap()
{
    this->hit_points = 100;
    this->max_hit_points = 100;
    this->energy_points = 100;
    this->max_energy_points = 100;
    this->level = 1;
    this->melee_attack_damage = 30;
    this->ranged_attack_damage = 20;
    this->armor_damage_reduction = 5;
    std::cout << this->name << " : Time to play..." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other):ClapTrap(other.name)
{
    ClapTrap::copy(other);
    std::cout << "We are legion! Go to pub)" << std::endl;
}

FragTrap::FragTrap(std::string name):ClapTrap(name)
{
    this->hit_points = 100;
    this->max_hit_points = 100;
    this->energy_points = 100;
    this->max_energy_points = 100;
    this->level = 1;
    this->melee_attack_damage = 30;
    this->ranged_attack_damage = 20;
    this->armor_damage_reduction = 5;
    std::cout << this->name << " : Time to play.." << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << this->name << " died" << std::endl;
}

FragTrap &FragTrap::operator = (const FragTrap &other)
{
    ClapTrap::copy(other);
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

class NinjaTrap: public virtual ClapTrap
{
    public:
        NinjaTrap(); 
        NinjaTrap(std::string name);
        NinjaTrap(const NinjaTrap &other);
        virtual ~NinjaTrap();
        NinjaTrap &operator =(const NinjaTrap &other);
        virtual void rangedAttack(std::string const & target) override;
        virtual void meleeAttack(std::string const & target) override;
        void ninjaShoebox(FragTrap &trap);
        void ninjaShoebox(ScavTrap &trap);
        void ninjaShoebox(ClapTrap &trap);
        void ninjaShoebox(NinjaTrap &trap);
};

NinjaTrap::NinjaTrap()
{
    this->hit_points = 60;
    this->max_hit_points = 60;
    this->energy_points = 120; 
    this->max_energy_points = 120;
    this->level = 1;
    this->melee_attack_damage = 60; 
    this->ranged_attack_damage = 5;
    this->armor_damage_reduction = 0;
    std::cout << this->name << " : I beat samurai" << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap &other):ClapTrap(other.name)
{
    ClapTrap::copy(other);
    std::cout << " Now we command Ninjas" << std::endl;
}

NinjaTrap::NinjaTrap(std::string name):ClapTrap(name)
{
    this->hit_points = 60;
    this->max_hit_points = 60;
    this->energy_points = 120; 
    this->max_energy_points = 120;
    this->level = 1;
    this->melee_attack_damage = 60; 
    this->ranged_attack_damage = 5;
    this->armor_damage_reduction = 0;
    std::cout << this->name << " : double ninjas" << std::endl;
}

NinjaTrap::~NinjaTrap()
{
    std::cout << this->name << " Ninja sepuko" << std::endl;
}

NinjaTrap &NinjaTrap::operator = (const NinjaTrap &other)
{
    ClapTrap::copy(other);
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

class SuperTrap: public FragTrap, public NinjaTrap
{
    public:
        SuperTrap();
        SuperTrap(std::string name);
        SuperTrap(const SuperTrap &other);
        virtual ~SuperTrap();
        SuperTrap &operator =(const SuperTrap &other);
        virtual void rangedAttack(std::string const & target) override;
        virtual void meleeAttack(std::string const & target) override;
};

SuperTrap::SuperTrap()
{
    this->hit_points = this->FragTrap::hit_points;
    this->max_hit_points = FragTrap::max_hit_points;
    this->energy_points = this->NinjaTrap::energy_points;; 
    this->max_energy_points = this->NinjaTrap::max_energy_points;
    this->level = 1;
    this->melee_attack_damage = this->NinjaTrap::melee_attack_damage;
    this->ranged_attack_damage = this->FragTrap::ranged_attack_damage;
    this->armor_damage_reduction = this->FragTrap::armor_damage_reduction;
    std::cout << this->name << " : I'm noname super class" << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap &other):ClapTrap(other.name),FragTrap(other.name),NinjaTrap(other.name)
{
    ClapTrap::copy(other);
    std::cout << this->name << " : I'm copy super class" << std::endl;
}

SuperTrap::SuperTrap(std::string name):ClapTrap(name), FragTrap(name), NinjaTrap(name)
{
    this->hit_points = this->FragTrap::hit_points;
    this->max_hit_points = FragTrap::max_hit_points;
    this->energy_points = this->NinjaTrap::energy_points;; 
    this->max_energy_points = this->NinjaTrap::max_energy_points;
    this->level = 1;
    this->melee_attack_damage = this->NinjaTrap::melee_attack_damage;
    this->ranged_attack_damage = this->FragTrap::ranged_attack_damage;
    this->armor_damage_reduction = this->FragTrap::armor_damage_reduction;
    std::cout << this->name << " : I' named super class" << std::endl;
}

SuperTrap::~SuperTrap()
{
    std::cout << this->name << " I'm dyed super class" << std::endl;
}

SuperTrap &SuperTrap::operator = (const SuperTrap &other)
{
    ClapTrap::copy(other);
    std::cout << "i'm equal super class" << std::endl;
    return *this;
}


void SuperTrap::rangedAttack(std::string const & target)
{
    FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack(std::string const & target)
{
    NinjaTrap::rangedAttack(target);
}

int main( void )
{
    SuperTrap anonim4;
    SuperTrap notAnonim4("sjennett");
    SuperTrap clone(anonim4);
    clone = notAnonim4;
    
    std::cout << std::endl;

    notAnonim4.rangedAttack("droid");
    notAnonim4.meleeAttack("someone");

    std::cout << std::endl;
}