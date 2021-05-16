#include<iostream>

class Victim
{
    protected:
        std::string name;
        Victim();
    public:
        Victim(const Victim &other);
        Victim(const std::string &name);
        std::string getName();
        virtual ~Victim();
        Victim &operator =(const Victim &other);
        virtual void getPolymorphed() const;
};

std::ostream &operator <<(std::ostream &output, Victim &other);