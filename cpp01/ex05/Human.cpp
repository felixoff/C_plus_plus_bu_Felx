#include "Human.hpp"

Brain &Human::getBrain()
{
    return this->brain;
}

std::string Human::identify()
{
    return this->brain.identify();
}