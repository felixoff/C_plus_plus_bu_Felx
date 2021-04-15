#include<iostream>

class Victim
{
    protected:
        std::string name;
        Victim();
    public:
        Victim(const Victim &other);
        Victim(const std::string &name);
        std::string getName();
        virtual ~Victim();
        Victim &operator =(const Victim &other);
        virtual void getPolymorphed() const;
};

Victim::Victim(const std::string &name):name(name)
{
    std::cout << "Some random victim called " << this->name <<" just appeared!" <<std::endl;
}

std::string Victim::getName()
{
    return (this->name);
}

Victim::Victim(const Victim &other):name(other.name)
{
}

Victim &Victim::operator =(const Victim &other)
{
    this->name = other.name;
    return *this;
}

Victim::~Victim()
{
    std::cout << "Victim "<<this->name << " just died for no apparent reason!"  <<std::endl;
}

void Victim::getPolymorphed() const
{
    std::cout << this->name << " has been turned into a cute little sheep!" << std::endl;
}

std::ostream &operator <<(std::ostream &output, Victim &other)
{
    std::cout << "I'm " << other.getName() << " and I like otters!" << std::endl;
    return output;
}

class Peon : public Victim
{
    private:
        Peon();
    public:
        Peon(const Peon &other);
        Peon(const std::string &name);
        std::string getName();
        virtual ~Peon();
        Peon &operator =(const Peon &other);
        virtual void getPolymorphed() const override;
};

Peon::Peon(const std::string &name):Victim(name)
{
    std::cout <<"Zog Zog"<< std::endl;
}

std::string Peon::getName()
{
    return (this->name);
}

Peon::Peon(const Peon &other):Victim(other.name)
{
}

Peon &Peon::operator =(const Peon &other)
{
    this->name = other.name;
    return *this;
}

Peon::~Peon()
{
    std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed() const
{
    std::cout << this->name << " has been turned into a pink pony!" << std::endl;
}

std::ostream &operator <<(std::ostream &output, Peon &other)
{
    std::cout << "I'm " << other.getName() << " and I like otters!" << std::endl;
    return output;
}

class Sorcerer
{
    private:
        std::string name;
        std::string title;
        Sorcerer();
    public:
        Sorcerer(const Sorcerer &other);
        Sorcerer(const std::string &name,const std::string &title);
        std::string getName();
        std::string getTitle();
        virtual ~Sorcerer();
        Sorcerer &operator =(const Sorcerer &other);
        void polymorph(Victim const &victim) const;
};

Sorcerer::Sorcerer(const std::string &name,const std::string &title):name(name),title(title)
{
    std::cout << this->name << " , " << this->title << ", is born!" <<std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &other):name(other.name),title(other.title)
{
}

Sorcerer &Sorcerer::operator =(const Sorcerer &other)
{
    this->name = other.name;
    this->title = other.title;
    return *this;
}

Sorcerer::~Sorcerer()
{
    std::cout << this->name << " , " << this->title << ", is dead. Consequences will never be the same!" <<std::endl;
}

std::string Sorcerer::getTitle()
{
    return (this->title);
}

std::string Sorcerer::getName()
{
    return (this->name);
}

void Sorcerer::polymorph(Victim const &victim) const
{
    victim.getPolymorphed();
}

std::ostream &operator <<(std::ostream &output, Sorcerer &other)
{
    std::cout << "I am " << other.getName() << ", " << other.getTitle() << ", and I like ponies!" << std::endl;
    return output;
}
int main()
{
    Sorcerer robert("Robert", "the Magnificent");
    Victim jim("Jimmy");
    Peon joe("Joe");
    std::cout << robert << jim << joe;
    robert.polymorph(jim);
    robert.polymorph(joe);
    return 0;
}