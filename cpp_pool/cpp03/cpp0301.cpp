#include<iostream>

class ScavTrap
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
        void rangedAttack(std::string const & target);
        void meleeAttack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void recoverEnergy(unsigned int amount);
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
"at range, causing " << this->ranged_attack_damage << \
    " points of damage!" << std::endl;
}

void ScavTrap::meleeAttack(std::string const & target)
{
    std::cout << "ScavTrap" << this->name <<" melee attacks " << target << \
    "at range, causing " << this->melee_attack_damage << \
    " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (amount-this->armor_damage_reduction >= this->hit_points)
    {
        this->hit_points = 0;
        std::cout << this->name << " : I lose..." << std::endl;
    }
    else if (this->armor_damage_reduction >= amount)
    {
        std::cout << this->name << " : I am so strong" << std::endl;
    }
    else 
    {
        std::cout << this->name << " : Please..... stop..." << std::endl;
        this->hit_points = this->hit_points + \
        this->armor_damage_reduction - amount;
    }
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (amount+this->hit_points >= this->max_hit_points)
    {
        this->hit_points = this->max_hit_points;
        std::cout << this->name << " : I'm cured from coronavirus!!! Thank you brother!" << std::endl;
    }
    else 
    {
        std::cout << this->name << " : More more more health" << std::endl;
        this->hit_points = this->hit_points + amount;
    }
}

void ScavTrap::recoverEnergy(unsigned int amount)
{
    if (amount+this->energy_points >= this->max_energy_points)
    {
        this->energy_points = this->max_energy_points;
        std::cout << this->name << " : Energy is full" << std::endl;
    }
    else 
    {
        std::cout << this->name<< " : more more more energy" << std::endl;
        this->energy_points = this->energy_points + amount;
    }
}

void ScavTrap::challengeNewcomer()
{
    std::cout<< this->name << ":" <<this->chalenges[rand() % 5] << std::endl;
}

int main( void )
{
    ScavTrap anonim;
    ScavTrap notAnonim("sjennett");
    ScavTrap clon(notAnonim);
    ScavTrap  peer;
    peer = anonim;

    clon.rangedAttack("droid");
    clon.meleeAttack("someone");
    clon.takeDamage(93);
    clon.takeDamage(32);
    clon.beRepaired(120);
    clon.takeDamage(99);
    clon.recoverEnergy(87);
    clon.challengeNewcomer();
    clon.challengeNewcomer();
    clon.challengeNewcomer();
    peer.challengeNewcomer();
    peer.challengeNewcomer();
    return 0;
}