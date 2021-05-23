#include "Convert.hpp"

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
int Convert::to_Int()
{
    errno = 0;
    int i = std::atoi(this->name.c_str());
    if (errno)
        throw ImpossibleToConvertException();
    return(i);
}
char  Convert::to_Char()
{
    errno = 0;
    int i = std::atoi(this->name.c_str());
    if (errno)
       throw ImpossibleToConvertException();
    char c = static_cast<char>(i);
    if (errno)
        throw ImpossibleToConvertException();
    return(c);
}
double Convert::to_Double()
{
    errno = 0;
    double  d = std::strtod(this->name.c_str(),NULL);
    if (errno)
        throw ImpossibleToConvertException();
    return(d);
}
float Convert::to_Float()
{
    errno = 0;
    float f = std::atof(this->name.c_str());
    if (errno)
        throw ImpossibleToConvertException();
    return(f);
}

const char *Convert::ImpossibleToConvertException::what() const throw()
{
    return "ImpossibleToConvertException";
}
