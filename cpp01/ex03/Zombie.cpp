#include  "Zombie.hpp"

Zombie::Zombie()
{
    this->type = "";
    this->name = "";
    std::cout << "I was born!!!" << std::endl;
}
Zombie::Zombie(std::string type, std::string name):type(type),name(name)
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