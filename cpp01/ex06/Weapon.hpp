#include<iostream>
#include<sstream>

class Weapon
{
    private:
        std::string type;
    public:
        Weapon(std::string type);
        virtual ~Weapon();
        void setType(std::string type);
        std::string const &getType();
};
