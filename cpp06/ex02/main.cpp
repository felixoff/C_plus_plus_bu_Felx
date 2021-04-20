#include "Base.hpp"
#include "C.hpp"
#include "B.hpp"
#include "A.hpp"

Base * generate(void)
{
    Base *genBase;
    int i;
    i = rand() % 3;
    if (i == 0)
        genBase = new A();
    if (i == 1)
        genBase = new B();
    if (i == 2)
        genBase = new C();
    return genBase;
}

void identify_from_pointer(Base * p)
{

    if (dynamic_cast<A*>(p)) 
    {
        std::cout << "A" << std::endl;
    }
        if (dynamic_cast<B*>(p)) 
    {
        std::cout << "B" << std::endl;
    }
        if (dynamic_cast<C*>(p)) 
    {
        std::cout << "C" << std::endl;
    }
}

void identify_from_reference( Base & p)
{

    try{
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }catch(std::bad_cast &e){
        try{
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        }
        catch(std::bad_cast &e){
            try{
                (void)dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;     
            }catch(std::bad_cast &e){}
        }
    }
}

int main()
{
    Base *base1 = new A();
    Base *base2 = new B();
    Base *base3 = generate();
    Base *base4 = generate();
    Base *base5 = generate();
    Base *base6 = generate();
    Base *base7 = generate();
    Base *base8 = generate();
    Base *base9 = generate();
    Base *base10 = generate();

    identify_from_pointer(base1);
    identify_from_pointer(base3);
    identify_from_reference(*base2);
    identify_from_reference(*base4);
    identify_from_reference(*base5);
    identify_from_reference(*base7);
    identify_from_reference(*base6);
    identify_from_reference(*base8);
    identify_from_reference(*base9);
    identify_from_reference(*base10);
}