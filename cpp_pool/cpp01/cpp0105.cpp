#include<iostream>
#include<sstream>
class Brain
{
    public:
        std::string identify();
};

std::string Brain::identify()
{
    std::stringstream s;
    s << (void *) this;
    return s.str(); 
}

class Human
{
    private:
        Brain brain;
    public:
        Brain &getBrain();
        std::string identify();
};

Brain &Human::getBrain()
{
    return this->brain;
}

std::string Human::identify()
{
    return this->brain.identify();
}

int main()
{
    Human bob;
    
    std::cout << bob.identify() << std::endl;
    std::cout << bob.getBrain().identify() << std::endl;
    return 0;
}