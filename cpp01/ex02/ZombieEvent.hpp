#include "Zombie.hpp"

class ZombieEvent
{
    private:
        std::string type;
    public:
        ZombieEvent();
        virtual ~ZombieEvent();

        void setZombieType(std::string type);
        Zombie* newZombie(std::string name);
        void randomChump(void);
};