#include "RadScorpion.hpp"
class Character
{
private:
    std::string name;
    int apcount;
    AWeapon *weapon;
    Character();
public:
Character(std::string const & name);
void recoverAP();
void equip(AWeapon* weapon);
void attack(Enemy* enemy);
virtual ~Character();
Character &operator =(const Character &other);
Character(const Character &other);
std::string const getName() const;
int getAPcount() const;
AWeapon *getWeapon();
};

std::ostream &operator <<(std::ostream &output, Character &other);