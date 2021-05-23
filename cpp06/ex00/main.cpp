#include "Convert.hpp"

int main(int argc, char **argv)
{
if (argc == 2)
{
    std::string s = argv[1];
    Convert conv(s);
    std::cout << " char : ";
    try{
    char c = conv.to_Char();
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
        int i = conv.to_Int(); 
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
        float f= conv.to_Float(); 
        f = static_cast<float>(f);
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
        double d= conv.to_Double(); 
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
}
    else
                std::cout << " bad argument" << std::endl;
    return(0);
}
