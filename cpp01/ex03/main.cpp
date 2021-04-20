#include  "ZombieHorde.hpp"
int main()
{
    setlocale(LC_ALL,"RUS");
    Zombie firstZombie("Independent","Dennis");
    firstZombie.announce();
    ZombieHorde horde(5);
    horde.announce();
    return(0);
}