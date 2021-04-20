#include <iostream>	
#include<ostream>
#include<exception>
#include "errno.h"

class Convert
{
    public:
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
        char to_Char();
        int  to_Int();
        double to_Double();
        float to_Float();

};
//std::ostream					&operator<<(std::ostream &os, Convert const &typestring);