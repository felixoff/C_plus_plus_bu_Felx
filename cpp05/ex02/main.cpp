#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentalPardonForm.hpp"
int main(void)
{
    std::string s0 = "Supervisor";
	Bureaucrat supervisor(s0, 1);
	std::cout << supervisor << std::endl;
    std::string s1 = "Francis";
	Bureaucrat francis(s1, 25);
	std::cout << francis << std::endl;

    std::string s2 = "home";
	Form *shrub = new ShrubberyCreationForm(s2);
	std::cout << *shrub << std::endl;
	shrub->beSigned(supervisor);
	//shrub->execute(francis);

    std::string s3 = "Francis";
	Form *pres = new PresidentialPardonForm(s3);
	std::cout << *pres << std::endl;
	supervisor.signForm(*pres);
	//pres->execute(supervisor);

    std::string s4 = "Bender";
	Form *robot = new RobotomyRequestForm(s4);
	std::cout << *robot << std::endl;
	robot->beSigned(supervisor);
	robot->execute(francis);
	francis.executeForm(*robot);
	francis.executeForm(*robot);

	std::cout << "---" << std::endl;

	try
	{
		francis.executeForm(*pres);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	try
	{
        std::string s5 = "Bender";
		RobotomyRequestForm robot = RobotomyRequestForm(s5);
		std::cout << robot << std::endl;
		robot.execute(supervisor);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	try
	{
        std::string s6 = "Francis";
		PresidentialPardonForm pres = PresidentialPardonForm(s6);
		std::cout << pres << std::endl;
		supervisor.signForm(pres);
		pres.execute(francis);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	try
	{
        std::string s7 = "Francis";
		PresidentialPardonForm pres = PresidentialPardonForm(s7);
		std::cout << pres << std::endl;
		supervisor.signForm(pres);
		francis.executeForm(pres);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	delete shrub;
	delete pres;
	delete robot;

	return (0);
}
