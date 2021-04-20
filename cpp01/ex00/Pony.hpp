#include<iostream>

class Pony
{
    private:
        std::string const name;
    public:
        Pony(std::string const name);
        virtual ~Pony();
        void fly();

};

void ponyOnTheStack();
void ponyOnTheHeap();
