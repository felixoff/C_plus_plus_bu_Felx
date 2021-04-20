#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n)
{
    this->type = "";
    this->n = n;
    this->zombies = new Zombie[n];
    for (int i = 0; i < this->n; i++)
    {
        const char *alphabet[] = {"a","b","c","d","e"};
        std::string s = "";
        for (int i=0; i< 5; i++)
            s+=alphabet[std::rand() % (sizeof alphabet/sizeof(char *))];
        zombies[i].setDescribtion("We are legion", s);
    }
    std::cout << "Event is begin!!!!!" << std::endl;
}

ZombieHorde::~ZombieHorde()
{
    std::cout << "Event is end!!!!!"<< std::endl;
    delete[] this->zombies;
}


void ZombieHorde::announce(void)
{
    for (int i = 0; i < this->n; i++)
    {
        this->zombies[i].announce();
    }
}
