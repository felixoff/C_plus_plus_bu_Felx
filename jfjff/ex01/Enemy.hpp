#include "PlasmaRifle.hpp"


class Enemy
{
private:
    Enemy();
protected:
    int hp;
    std::string type;
public:
    Enemy(int hp, std::string const & type);
    virtual ~Enemy();
    Enemy(const Enemy &other);
    Enemy &operator =(const Enemy&other);
    std::string const getType() const;
    int getHP() const;
    virtual void takeDamage(int damage);
};
