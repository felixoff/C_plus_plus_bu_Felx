#include <iostream>
#include <sstream>
struct Data
{
    std::string s1;
    int digit;
    std::string s2;
};

void * serialize(void);

Data * deserialize(void * streamBytes);
