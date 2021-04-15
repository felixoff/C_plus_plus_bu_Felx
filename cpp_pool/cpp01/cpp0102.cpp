#include<iostream>
class Zombie
{
    private:
        std::string type;
        std::string name;
    public:
        Zombie(std::string type, std::string name);
        virtual ~Zombie();

        void announce();
};

Zombie::Zombie(std::string type, std::string name):name(name),type(type)
{
    std::cout << "I was born!!!" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "I was died"<< std::endl;
}

void Zombie::announce()
{
    std::cout << "<"+this->name +"("+this->type+")> Braiiiiiiinnnssss..." << std::endl;
}

class ZombieEvent
{
    private:
        std::string type;
    public:
        ZombieEvent();
        virtual ~ZombieEvent();

        void setZombieType(std::string type);
        Zombie* newZombie(std::string name);
        void randomChump(void);
};

ZombieEvent::ZombieEvent()
{
    this->type = "";
    std::cout << "Event is begin!!!!!" << std::endl;
}

ZombieEvent::~ZombieEvent()
{
    std::cout << "Event is end!!!!!"<< std::endl;
}

void ZombieEvent::setZombieType(std::string type)
{
    this->type = type;
}

Zombie* ZombieEvent::newZombie(std::string name)
{
    Zombie *newZombo = new Zombie(this->type,name);
    return newZombo;
}

void ZombieEvent::randomChump(void)
{
    const char *alphabet[] = {"a","b","c","d","e"};
    std::string s = "";
    for (int i=0; i< 5; i++)
        s+=alphabet[std::rand() % (sizeof alphabet/sizeof(char *))];
    Zombie zombo(this->type,s);
    zombo.announce();
}

int main()
{
    setlocale(LC_ALL,"RUS");
    Zombie firstZombie("Independent","Dennis");
    firstZombie.announce();
    ZombieEvent *evento = new ZombieEvent();
    evento->setZombieType("Dependent");
    evento->randomChump();
    Zombie *secondZombie = evento->newZombie("Andrew");
    secondZombie->announce();
    delete secondZombie;
    delete evento;
    return(0);
}