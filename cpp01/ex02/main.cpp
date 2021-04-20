#include "ZombieEvent.hpp"

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