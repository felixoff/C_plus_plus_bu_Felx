#include  "Zombie.hpp"

class ZombieHorde
{
    private:
        std::string type;
        Zombie *zombies;
        int n;
    public:
        ZombieHorde(int n);
        virtual ~ZombieHorde();

        void announce(void);
};
