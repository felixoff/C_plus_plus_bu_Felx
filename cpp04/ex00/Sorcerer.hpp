#include "Victim.hpp"

class Sorcerer
{
    private:
        std::string name;
        std::string title;
        Sorcerer();
    public:
        Sorcerer(const Sorcerer &other);
        Sorcerer(const std::string &name,const std::string &title);
        std::string getName();
        std::string getTitle();
        virtual ~Sorcerer();
        Sorcerer &operator =(const Sorcerer &other);
        void polymorph(Victim const &victim) const;
};
std::ostream &operator <<(std::ostream &output, Sorcerer &other);