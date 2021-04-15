#include<iostream>
class Zombie
{
    private:
        std::string type;
        std::string name;
    public:
        Zombie();
        Zombie(std::string type, std::string name);
        virtual ~Zombie();
        void setDescribtion(std::string type, std::string name);

        void announce();
};

Zombie::Zombie()
{
    this->type = "";
    this->name = "";
    std::cout << "I was born!!!" << std::endl;
}
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

void Zombie::setDescribtion(std::string type, std::string name)
{
    this->type = type;
    this->name = name;
}

class ZombieHorde
{
    private:
        std::string type;
        Zombie *zombies;
        int n;
    public:
        ZombieHorde(int n);
        virtual ~ZombieHorde();

        void announce(void);
};

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

int main()
{
    setlocale(LC_ALL,"RUS");
    Zombie firstZombie("Independent","Dennis");
    firstZombie.announce();
    ZombieHorde horde(5);
    horde.announce();
    return(0);
}