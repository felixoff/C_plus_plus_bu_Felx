#include "Zombie.hpp"

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
