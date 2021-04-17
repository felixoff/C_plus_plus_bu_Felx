#include <iostream>	
#include<ostream>
#include "errno.h"
class Convert
{
    private:
        std::string name;
        Convert();
    public:
        Convert(std::string &name);
        Convert(Convert const &other);
        ~Convert();
        Convert &operator =(Convert const &other);
   //     operator std::string const &(void) const;
        class ImpossibleToConvertException:public std::exception
        {           
            public:
            const char *what() const throw();
        };
//      class NotDisplayedSimbolException:public std::exception
//        {
  //          public:
   //         const char *what() const throw();         
  //      };
        char to_Char(std::string &s);
        int  to_Int(std::string &s);
        double to_Double(std::string &s);
        float to_Float(std::string &s);

};
std::ostream					&operator<<(std::ostream &os, Convert const &typestring);

//							Convert::operator std::string const &(void) const
//{
//	return (this->name);
//}

//std::ostream				&operator<<(std::ostream &os, Convert typestring)
//{
//	os << static_cast<std::string>(typestring);
//	return (os);
//}

Convert::Convert():name("")
{
}
Convert::Convert(std::string &name):name(name)
{
}
Convert::Convert(Convert const &other):name(other.name)
{
}
Convert::~Convert()
{
}
Convert &Convert::operator =(Convert const &other)
{
    this->name = other.name;
    return *this;
}
int Convert::to_Int(std::string &s)
{
    int i = std::atoi(this->name.c_str());
    if (errno)
        throw ImpossibleToConvertException();
    return(i);
}
char  Convert::to_Char(std::string &s)
{
    int i = std::atoi(this->name.c_str());
    if (errno)
        throw ImpossibleToConvertException();
 //   if (i < 32 || i > 126)
 //       throw NotDisplayedSimbolException();
    char c = static_cast<char>(i);
    if (errno)
        throw ImpossibleToConvertException();
    return(c);
}
double Convert::to_Double(std::string &s)
{
    double d = std::strtod(this->name.c_str(),NULL);
    if (errno)
        throw ImpossibleToConvertException();
    return(d);
}
float Convert::to_Float(std::string &s)
{
    float f = std::atof(this->name.c_str());
    if (errno)
        throw ImpossibleToConvertException();
    return(f);
}

const char *Convert::ImpossibleToConvertException::what() const throw()
{
    return "ImpossibleToConvertException";
}

//const char *Convert::NotDisplayedSimbolException::what() const throw()
//{
 //   return "NotDisplayedSimbolException";
//}

int main(int argc, char **argv)
{
if (argc == 2)
{
    std::string s = argv[1];
    Convert conv(s);
    std::cout << " char : ";
    try{
    char c = conv.to_Char(s);
    if (!std::isprint(c))
        if (s == "nan" || s == "+inff" || s == "-inff"|| s == "+inf" || s == "-inf")
                std::cout << " impossible" << std::endl;
        else
            std::cout << " Non displayable" << std::endl;
    else   
            std::cout << '\'' << c << '\'' << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << " int : ";
    try
    {
        int i = conv.to_Int(s); 
        i = static_cast<int>(i);
        if (s == "nan" || s == "+inff" || s == "-inff" || s == "+inf" || s == "-inf")
                std::cout << " impossible" << std::endl;
        else
            std::cout << i << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::fixed;
	std::cout.precision(1);

    std::cout << " float : ";
    try
    {
        float f= conv.to_Float(s); 
     //   f = static_cast<float>(f);
        if (s == "nan")
                std::cout << " nan";
        else if (s == "+inf" || s == "+inff")
                std::cout << " +inf";
        else if (s == "-inf" || s == "-inff")
                std::cout << " -inf";
        else
            std::cout << f;
         std::cout << "f" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << " double : ";
    try
    {
        double d= conv.to_Double(s); 
        d = static_cast<double>(d);
        if (s == "nan")
                std::cout << " nan" << std::endl;
        else if (s == "+inf" || s == "+inff")
                std::cout << " +inf" << std::endl;
        else if (s == "-inf" || s == "-inff")
                std::cout << " -inf" << std::endl;
        else
            std::cout << d << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
 //   char c = static_cast<char>(i);

 //   if (argc > 1)
 //   {
 //       std::cout << typeid(argv[1]).name() << std::endl;
 //   }
    //     std::cout << c << std::endl;
}
    return(0);
}
