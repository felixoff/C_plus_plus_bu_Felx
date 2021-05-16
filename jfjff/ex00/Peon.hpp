#include "Sorcerer.hpp"

class Peon : public Victim
{
    private:
        Peon();
    public:
        Peon(const Peon &other);
        Peon(const std::string &name);
        std::string getName();
        virtual ~Peon();
        Peon &operator =(const Peon &other);
        virtual void getPolymorphed() const;
};
