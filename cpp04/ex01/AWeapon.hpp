#include<iostream>
class AWeapon
{
protected:
    std::string name;
    int apcost;
    int damage;
private:
    AWeapon();
public:
    AWeapon(std::string const & name, int apcost, int damage);
    AWeapon(const AWeapon &other);
    AWeapon &operator =(const AWeapon &other);
    virtual ~AWeapon();
    std::string const getName() const;
    int getAPCost() const;
    int getDamage() const;
    virtual void attack() const = 0;
};