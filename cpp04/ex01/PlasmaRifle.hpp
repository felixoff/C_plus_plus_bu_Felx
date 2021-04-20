#include "PowerFist.hpp"

class PlasmaRifle: public AWeapon
{
public:
    PlasmaRifle();
    PlasmaRifle(const PlasmaRifle &other);
    PlasmaRifle &operator =(const PlasmaRifle &other);
    virtual ~PlasmaRifle();
    void attack() const;
};

