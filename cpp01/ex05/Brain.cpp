#include "Brain.hpp"

std::string Brain::identify()
{
    std::stringstream s;
    s << (void *) this;
    return s.str(); 
}