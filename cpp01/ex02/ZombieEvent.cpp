#include "ZombieEvent.hpp"

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