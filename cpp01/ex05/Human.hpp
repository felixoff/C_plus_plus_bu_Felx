#include"Brain.hpp"

class Human
{
    private:
        Brain brain;
    public:
        Brain &getBrain();
        std::string identify();
};