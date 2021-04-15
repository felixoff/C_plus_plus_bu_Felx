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

Pony::Pony(std::string const name):name(name)
{
    std::cout << "I was born!!!"<< this->name << std::endl;
}

Pony::~Pony()
{
    std::cout << "I was died"<< std::endl;
}

void Pony::fly()
{
    std::cout << "I'm flying!!!"<< this->name << std::endl;
}

void ponyOnTheStack()
{
    Pony stackPony("I'm Stack Pony");
    stackPony.fly();
}

void ponyOnTheHeap()
{
    Pony *heapPony = new Pony("I'm Heap Pony");
    heapPony->fly();
    delete heapPony;
}

int main()
{
    setlocale(LC_ALL,"RUS");
    ponyOnTheStack();
    ponyOnTheHeap();
    return(0);
}