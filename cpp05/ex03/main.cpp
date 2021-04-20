#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentalPardonForm.hpp"
#include "Intern.hpp"

int				main(void)
{
	Intern					joe;

	//joe.makeForm("univers creation", "just here");
	Form					*form1 = joe.makeForm("shrubbery creation", "mars");
	Form					*form2 = joe.makeForm("robotomy request", "terre");
	Form					*form3 = joe.makeForm("presidential pardon", "president");
	std::cout << *form1 << std::endl;

	try
	{
		std::string s1 = "Bob";
		Bureaucrat	bob(s1, 150);
		std::cout << bob;
		bob.signForm(*form1);
		bob.executeForm(*form1);
		std::cout << *form1;
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR Bob" << std::endl;
	}

	try
	{
		std::string s2 = "Jack";
		Bureaucrat	jack(s2, 140);
		std::cout << jack;
		jack.signForm(*form1);
		jack.executeForm(*form1);
		std::cout << *form1;
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR Jack" << std::endl;
	}

	try
	{
		std::string s3 = "President";
		Bureaucrat	jule(s3, 2);
		std::cout << jule;
		jule.executeForm(*form1);
		std::cout << *form1;

		jule.signForm(*form2);
		jule.executeForm(*form2);
		std::cout << *form2;

		jule.signForm(*form3);
		jule.executeForm(*form3);
		std::cout << *form3;
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR Jule" << std::endl;
	}

	return (0);
}