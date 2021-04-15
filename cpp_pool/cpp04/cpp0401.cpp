#include<iostream>
class AWeapon
{
protected:
    std::string name;
    int damage;
    int apcost;
private:
    AWeapon();
public:
    AWeapon(std::string const & name, int apcost, int damage);
    AWeapon(const AWeapon &other);
    AWeapon &operator =(const AWeapon &other);
    virtual ~AWeapon();
    std::string const getName() const;
    int getAPCost() const;
    int getDamage() const;
    virtual void attack() const = 0;
};

AWeapon::AWeapon(std::string const & name, int apcost, int damage):name(name),apcost(apcost),damage(damage)
{

}

AWeapon::AWeapon(const AWeapon &other):name(other.name),apcost(other.apcost),damage(other.damage)
{
}

AWeapon &AWeapon::operator =(const AWeapon &other)
{
    this->name = other.name;
    this->damage = other.damage;
    this->apcost = other.apcost;
    return *this;
}

AWeapon:: ~AWeapon()
{
}

std::string const AWeapon::getName() const
{
    return this->name;
}

int AWeapon::getAPCost() const
{
    return this->apcost;
}

int AWeapon::getDamage() const
{
    return this->damage;
}


class PlasmaRifle: public AWeapon
{
public:
    PlasmaRifle();
    PlasmaRifle(const PlasmaRifle &other);
    PlasmaRifle &operator =(const PlasmaRifle &other);
    virtual ~PlasmaRifle();
    void attack() const;
};

PlasmaRifle::PlasmaRifle():AWeapon("Plasma Rifle",5,21)
{
}

PlasmaRifle::PlasmaRifle(const PlasmaRifle &other):AWeapon(other.name,other.apcost,other.damage)
{
}

PlasmaRifle &PlasmaRifle::operator =(const PlasmaRifle &other)
{
    this->name = other.name;
    this->damage = other.damage;
    this->apcost = other.apcost;
    return *this;
}

PlasmaRifle:: ~PlasmaRifle()
{
}

void PlasmaRifle::attack() const
{
    std::cout << "* piouuu piouuu piouuu *" << std::endl;;
}

class PowerFist: public AWeapon
{
public:
    PowerFist();
    PowerFist(const PowerFist &other);
    PowerFist &operator =(const PowerFist &other);
    virtual ~PowerFist();
    void attack() const;
};

PowerFist::PowerFist():AWeapon("Power Fist",8,50)
{
}

PowerFist::PowerFist(const PowerFist &other):AWeapon(other.name,other.apcost,other.damage)
{
}

PowerFist &PowerFist::operator =(const PowerFist &other)
{
    this->name = other.name;
    this->damage = other.damage;
    this->apcost = other.apcost;
    return *this;
}

PowerFist:: ~PowerFist()
{
}

void PowerFist::attack() const
{
    std::cout << "* pschhh... SBAM! *" << std::endl;
}

class Enemy
{
private:
    Enemy();
protected:
    int hp;
    std::string type;
public:
    Enemy(int hp, std::string const & type);
    virtual ~Enemy();
    Enemy(const Enemy &other);
    Enemy &operator =(const Enemy&other);
    std::string const getType() const;
    int getHP() const;
    virtual void takeDamage(int damage);
};

Enemy::Enemy(int hp, std::string const & type):hp(hp),type(type)
{
}

Enemy::Enemy(const Enemy &other):hp(other.hp),type(other.type)
{
}

Enemy &Enemy::operator =(const Enemy &other)
{
    this->hp = other.hp;
    this->type = other.type;
    return *this;
}

Enemy:: ~Enemy()
{
}

std::string const Enemy::getType() const
{
    return this->type;
}

int Enemy::getHP() const
{
    return this->hp;
}

void Enemy::takeDamage(int damage)
{
    if (damage >= 0)
        this->hp = this->hp - damage;
}

class SuperMutant:public Enemy
{
public:
    SuperMutant();
    virtual ~SuperMutant();
    SuperMutant &operator =(const SuperMutant&other);
    SuperMutant(const SuperMutant &other);
    virtual void takeDamage(int damage);
};

SuperMutant::SuperMutant(const SuperMutant &other):Enemy(other.hp,other.type)
{
}

SuperMutant::SuperMutant():Enemy(170,"Super Mutant")
{
    std::cout <<  "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant &SuperMutant::operator =(const SuperMutant &other)
{
    this->hp = other.hp;
    this->type = other.type;
    return *this;
}

SuperMutant:: ~SuperMutant()
{
    std::cout <<  "Aaargh..." << std::endl;
}

void SuperMutant::takeDamage(int damage)
{
    Enemy::takeDamage(damage-3);
}

class RadScorpion :public Enemy
{
public:
    RadScorpion();
    virtual ~RadScorpion();
    RadScorpion(const RadScorpion &other);
    RadScorpion &operator =(const RadScorpion&other);
    virtual void takeDamage(int damage);
};

RadScorpion::RadScorpion(const RadScorpion &other):Enemy(other.hp,other.type)
{
}

RadScorpion::RadScorpion():Enemy(80, "RadScorpion")
{
    std::cout << "* click click click *" << std::endl;
}

RadScorpion &RadScorpion::operator =(const RadScorpion &other)
{
    this->hp = other.hp;
    this->type = other.type;
    return *this;
}

RadScorpion:: ~RadScorpion()
{
    std::cout <<   "* SPROTCH *" << std::endl;
}

void RadScorpion::takeDamage(int damage)
{
    Enemy::takeDamage(damage);
}

class Character
{
private:
    std::string name;
    int apcount;
    AWeapon *weapon;
    Character();
public:
Character(std::string const & name);
void recoverAP();
void equip(AWeapon* weapon);
void attack(Enemy* enemy);
virtual ~Character();
Character &operator =(const Character &other);
Character(const Character &other);
std::string const getName() const;
int getAPcount() const;
AWeapon *getWeapon();
};

AWeapon *Character::getWeapon()
{
    return this->weapon;
}

int Character::getAPcount() const
{
    return this->apcount;
}

Character::Character(std::string const & name):name(name),apcount(40),weapon(NULL)
{
}

Character::Character(const Character &other):name(other.name),apcount(other.apcount),weapon(other.weapon)
{
}

Character &Character::operator =(const Character &other)
{
    this->apcount = other.apcount;
    this->name = other.name;
    this->weapon = other.weapon;
    return *this;
}

Character:: ~Character()
{
}

void Character::recoverAP()
{
    if (this->apcount + 10 >= 40)
        this->apcount = 40;
    else
        this->apcount = this->apcount + 10;
}

std::string const Character::getName() const
{
    return this->name;
}

void Character::equip(AWeapon* weapon)
{
    this->weapon = weapon;
}

void Character::attack(Enemy* enemy)
{
    std::cout <<  this->getName() << " attacks " <<enemy->getType() << " with a " << this->getWeapon()->getName() << std::endl;
    if (this->getWeapon() == NULL || enemy == NULL)
        return;
    if (this->apcount < this->getWeapon()->getAPCost())
        return;
    this->apcount = this->apcount - this->getWeapon()->getAPCost();
    this->getWeapon()->attack();
    enemy->takeDamage(this->getWeapon()->getDamage());
    if (enemy->getHP() <= 0)
       delete enemy;
}

std::ostream &operator <<(std::ostream &output, Character &other)
{
    if (other.getWeapon() != NULL)
        std::cout <<  other.getName() << " has " << other.getAPcount() << \
        " AP and wields a " << other.getWeapon()->getName()<< std::endl;
    else
        std::cout << other.getName() <<" has " << other.getAPcount() << \
        " AP and is unarmed"<<std::endl;
    return output;
}

int main()
{
Character* me = new Character("me");
std::cout << *me;
Enemy* b = new RadScorpion();
AWeapon* pr = new PlasmaRifle();
AWeapon* pf = new PowerFist();
me->equip(pr);
std::cout << *me;
me->equip(pf);
me->attack(b);
std::cout << *me;
me->equip(pr);
std::cout << *me;
me->attack(b);
std::cout << *me;
me->attack(b);
std::cout << *me;
return 0;
}