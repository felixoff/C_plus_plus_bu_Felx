#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else 
		while(i < argc)
	    {
		//	std::string str(argv[i]);
			std::string str = std::string(argv[i]);
			for (size_t j = 0; j<str.length();j++)
				std::cout << (char)std::toupper(str[j]);
			std::cout << std::endl;
			i++;
		}
		return(0);
}