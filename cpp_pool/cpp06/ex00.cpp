#include <iostream>	
#include <typeinfo>

class Convert
{
    private:

    public:
        Convert();
        Convert(Convert const &other);
        ~Convert();
        Convert &operator =(Convert const &other);
        void convert(char c);
        void convert(int i);
        void convert(double d);
        void convert(float f);
};

int main(int argc, char **argv)
{
    int i = 97;
    char c = static_cast<char>(i);

 //   if (argc > 1)
 //   {
 //       std::cout << typeid(argv[1]).name() << std::endl;
 //   }
         std::cout << c << std::endl;
    return(0);
}
