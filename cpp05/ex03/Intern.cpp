#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern &other)
{
    (void)other;
}
    
Intern::~Intern()
{
}

Intern &Intern::operator =(Intern &other)
{
    (void)other;
    return *this;
}

Form *Intern::makeShrubberyCreationForm(std::string target) const
{
      Form *form;  
    form = new ShrubberyCreationForm(target);
    return form;
}
Form *Intern::makeRobotomyRequestForm(std::string target) const
{
    return new RobotomyRequestForm(target);
}
Form *Intern::makePresidentialPardonForm(std::string target) const
{
    return new PresidentialPardonForm(target); 
}

Form *Intern::makeForm(std::string name,std::string target)
{
    std::string mas[3] = {"shrubbery creation","robotomy request", "presidential pardon"};
    int i = 0;
    while (i < 3 && mas[i] != name)
        i++;
    if (i == 3)
        throw FormNotExistsException();
    Form		*(Intern::*fnsPtr[3])(std::string target) const = \
	{&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};
    std::cout << "Intern creates <"<< name <<">"<<std::endl;
	return (this->*fnsPtr[i])(target);
}


const char *Intern::FormNotExistsException::what() const throw()
{
    return "Intern::FormNotExistsException";
}
