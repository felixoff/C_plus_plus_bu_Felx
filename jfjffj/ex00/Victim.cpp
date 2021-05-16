#include "Victim.hpp"


Victim::Victim(const std::string &name):name(name)
{
    std::cout << "Some random victim called " << this->name <<" just appeared!" <<std::endl;
}

std::string Victim::getName()
{
    return (this->name);
}

Victim::Victim(const Victim &other):name(other.name)
{
}

Victim &Victim::operator =(const Victim &other)
{
    this->name = other.name;
    return *this;
}

Victim::~Victim()
{
    std::cout << "Victim "<<this->name << " just died for no apparent reason!"  <<std::endl;
}

void Victim::getPolymorphed() const
{
    std::cout << this->name << " has been turned into a cute little sheep!" << std::endl;
}

std::ostream &operator <<(std::ostream &output, Victim &other)
{
    std::cout << "I'm " << other.getName() << " and I like otters!" << std::endl;
    return output;
}
