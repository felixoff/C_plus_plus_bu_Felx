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