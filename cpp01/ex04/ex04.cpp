#include<iostream>
int main()
{
    std::string str =  "HI THIS IS BRAIN";
    std::string *pointString = &str;
    std::string &refString = str;
    std::cout << str << std::endl;
    std::cout << *pointString << std::endl;
    std::cout << refString << std::endl;
    return 0;
}