#include "Sorcerer.hpp"

Sorcerer::Sorcerer(const std::string &name,const std::string &title):name(name),title(title)
{
    std::cout << this->name << " , " << this->title << ", is born!" <<std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &other):name(other.name),title(other.title)
{
}

Sorcerer &Sorcerer::operator =(const Sorcerer &other)
{
    this->name = other.name;
    this->title = other.title;
    return *this;
}

Sorcerer::~Sorcerer()
{
    std::cout << this->name << " , " << this->title << ", is dead. Consequences will never be the same!" <<std::endl;
}

std::string Sorcerer::getTitle()
{
    return (this->title);
}

std::string Sorcerer::getName()
{
    return (this->name);
}

void Sorcerer::polymorph(Victim const &victim) const
{
    victim.getPolymorphed();
}

std::ostream &operator <<(std::ostream &output, Sorcerer &other)
{
    std::cout << "I am " << other.getName() << ", " << other.getTitle() << ", and I like ponies!" << std::endl;
    return output;
}