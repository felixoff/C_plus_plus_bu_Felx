#include <iostream>

void memoryLeak()
{
std::string* panther = new std::string("String panther");
std::cout << *panther << std::endl;
delete panther;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    memoryLeak();
    return 0;
}