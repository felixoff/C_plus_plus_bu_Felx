#ifndef INTERN_H
#define INTERN_H

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentalPardonForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(Intern &other);
        ~Intern();
        Intern &operator =(Intern &other);
        Form *makeShrubberyCreationForm(std::string target) const;
        Form *makeRobotomyRequestForm(std::string target) const;
        Form *makePresidentialPardonForm(std::string target) const;
        Form *makeForm(std::string name,std::string target);
        class FormNotExistsException:public std::exception
        {
            const char *what() const throw();
        };
};
#endif