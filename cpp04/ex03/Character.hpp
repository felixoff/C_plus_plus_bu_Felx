#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.hpp"
#include <iostream>
class Character:public ICharacter
{
    private:
        AMateria *mater[4];
        std::string name;
        Character();
    public:
        Character(std::string const &name);
        virtual ~Character();
	    Character(Character const &other);
	    Character &operator =(const Character &other);
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);       
};

#endif