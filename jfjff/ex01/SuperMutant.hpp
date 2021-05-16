#include "Enemy.hpp"


class SuperMutant:public Enemy
{
public:
    SuperMutant();
    virtual ~SuperMutant();
    SuperMutant &operator =(const SuperMutant&other);
    SuperMutant(const SuperMutant &other);
    virtual void takeDamage(int damage);
};
