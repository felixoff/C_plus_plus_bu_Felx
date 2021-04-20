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
