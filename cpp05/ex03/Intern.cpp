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

Form *Intern::makeForm(std::string name,std::string target)
{
    Form *form;
    if (name == "shrubbery creation")
        form = new ShrubberyCreationForm(target);
    else if (name == "robotomy request")
        form = new RobotomyRequestForm(target);
    else if (name == "presidential pardon")
        form = new PresidentialPardonForm(target);
    else
        throw FormNotExistsException();
    std::cout << "Intern creates <"<< *form <<">"<<std::endl;
    return form;
}

const char *Intern::FormNotExistsException::what() const throw()
{
    return "Intern::FormNotExistsException";
}
