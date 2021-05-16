#include "Peon.hpp"


Peon::Peon(const std::string &name):Victim(name)
{
    std::cout <<"Zog Zog"<< std::endl;
}

std::string Peon::getName()
{
    return (this->name);
}

Peon::Peon(const Peon &other):Victim(other.name)
{
}

Peon &Peon::operator =(const Peon &other)
{
    this->name = other.name;
    return *this;
}

Peon::~Peon()
{
    std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed() const
{
    std::cout << this->name << " has been turned into a pink pony!" << std::endl;
}

std::ostream &operator <<(std::ostream &output, Peon &other)
{
    std::cout << "I'm " << other.getName() << " and I like otters!" << std::endl;
    return output;
}
