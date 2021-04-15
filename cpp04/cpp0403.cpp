#include<iostream>
class AMateria;

class ICharacter
{
public:
virtual ~ICharacter() {}
virtual std::string const & getName() const = 0;
virtual void equip(AMateria* m) = 0;
virtual void unequip(int idx) = 0;
virtual void use(int idx, ICharacter& target) = 0;
};

class AMateria
{
protected:
std::string type;
unsigned int _xp;
private:
AMateria();
public:
AMateria(std::string const & type);
AMateria(AMateria const &other);
AMateria &operator =(AMateria const &other);
virtual ~AMateria();
std::string const & getType() const; 
unsigned int getXP() const; 
virtual AMateria* clone() const = 0;
virtual void use(ICharacter& target);
};


class Character:public ICharacter
{
    private:
        AMateria *mater[4];
        std::string name;
        Character();
    public:
        Character(std::string const &name);
        virtual ~Character();
	    Character(Character const &other);
	    Character &operator =(const Character &other);
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);       
};


std::string const & AMateria::getType() const
{
    return this->type;
}

unsigned int AMateria::getXP() const
{
    return this->_xp;
}

AMateria::AMateria(std::string const & type):type(type),_xp(0)
{
}

AMateria::AMateria(AMateria const &other):type(other.type),_xp(other._xp)
{
}

AMateria &AMateria::operator =(AMateria const &other)
{
    this->type = other.type;
    this->_xp = other._xp;
    return(*this);
}

AMateria::~AMateria()
{
}

void AMateria::use(ICharacter& target)
{
    this->_xp = this->_xp + 10;
}

class Ice:public AMateria
{
public:
Ice();
Ice(Ice const &other);
Ice &operator =(Ice const &other);
virtual ~Ice();
virtual AMateria* clone() const;
virtual void use(ICharacter& target);
};

Ice::Ice(Ice const &other):AMateria(other.type)
{  
}

Ice &Ice::operator =(Ice const &other)
{
    this->type = other.type;
    this->_xp = other._xp;
    return(*this);
}

Ice::Ice():AMateria("ice")
{
}

Ice::~Ice()
{
}

void Ice::use(ICharacter& target)
{
    std::cout <<"* shoots an ice bolt at "<< target.getName() <<" *" <<std::endl;
    AMateria::use(target);
}

class Cure:public AMateria
{
public:
Cure();
Cure(Cure const &other);
Cure &operator =(Cure const &other);
virtual ~Cure();
virtual AMateria* clone() const;
virtual void use(ICharacter& target);
};

Cure::Cure(Cure const &other):AMateria(other.type)
{  
}

Cure &Cure::operator =(Cure const &other)
{
    this->type = other.type;
    this->_xp = other._xp;
    return(*this);
}

Cure::Cure():AMateria("cure")
{
}

Cure::~Cure()
{
}

void Cure::use(ICharacter& target)
{
    std::cout <<"* heals NAME's wounds *"<< target.getName() <<" *" <<std::endl;
    AMateria::use(target);
}

AMateria *Ice::clone() const
{
    AMateria *mater = new Cure();
    return (mater);
}
AMateria *Cure::clone() const
{
    AMateria *mater = new Ice();
    return (mater);
}

Character::Character(std::string const &name):name(name)
{
    for (int i = 0; i < 4; i++)
        this->mater[i] = NULL;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        delete this->mater[i];
}

Character::Character(Character const &other):name(other.name)
{
    for (int i = 0; i < 4; i++)
        this->mater[i] = other.mater[i];
}

Character &Character::operator =(const Character &other)
{
    this->name = other.name;
    for (int i = 0; i < 4; i++)
        delete this->mater[i];
    for (int i = 0; i < 4; i++)
        this->mater[i] = other.mater[i];
    return *this;
}

std::string const & Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria* m)
{
    for (int i = 0;i < 4; i++)
    {
        if (m && this->mater[i] == NULL)
        {
            this->mater[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 0 || this->mater[idx]==NULL )
        return;
    this->mater[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3 || this->mater[idx]==NULL )
        return;
    this->mater[idx]->use(target);
}

class IMateriaSource
{
public:
virtual ~IMateriaSource() {}
virtual void learnMateria(AMateria*) = 0;
virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource:public IMateriaSource
{
    private:
        AMateria *mater[4];
    public:
        MateriaSource();
        virtual ~MateriaSource();
	    MateriaSource(MateriaSource const &other);
	    MateriaSource &operator =(const MateriaSource &other);
        void learnMateria(AMateria* m);
        AMateria* createMateria(std::string const & type);
};

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->mater[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete this->mater[i];
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
    for (int i = 0; i < 4; i++)
        this->mater[i] = other.mater[i];
}

MateriaSource &MateriaSource::operator =(const MateriaSource &other)
{
    for (int i = 0; i < 4; i++)
        delete this->mater[i];
    for (int i = 0; i < 4; i++)
        this->mater[i] = other.mater[i];
    return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (m && this->mater[i] == NULL)
        {
            this->mater[i] = m;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0;i < 4; i++)
    {
        if (this->mater[i]->getType() == type)
        {
            return this->mater[i];
        }
    }
    return 0;
}

int main()
{
IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());
ICharacter* me = new Character("me");
AMateria* tmp;
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
ICharacter* bob = new Character("bob");
me->use(0, *bob);
me->use(1, *bob);
delete bob;
delete me;
delete src;
return 0;
}
