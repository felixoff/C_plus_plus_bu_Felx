#include "Bureaucrat.hpp"
#include "Form.hpp"


int				main(void)
{
	srand(time(0));
	Form		form("Form 42C", 21, 21);
	std::cout << form;

	try
	{
		Bureaucrat	bob("Bob", 42);
		std::cout << bob;
		bob.signForm(form);
		std::cout << form;
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR Bob" << std::endl;
	}

	try
	{
		Bureaucrat	jule("Jule", 2);
		std::cout << jule;
		jule.signForm(form);
		std::cout << form;
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR Jule" << std::endl;
	}

	return (0);
}