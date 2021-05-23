#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H
#include "Form.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm :public Form
{
    private:
        std::string &target;
        ShrubberyCreationForm();
        static std::string const trees[3];
    public:
        ShrubberyCreationForm(std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator =(ShrubberyCreationForm &other);
        std::string const getTarget() const;
        void execute(Bureaucrat const & executor) const;
        class FormNotSigned:public std::exception
        {
            const char *what() const throw();
        };
        class GradeTooLowExceptionToExec:public std::exception
        {
            const char *what() const throw();
        };
        class CannotOpenFileExeption:public std::exception
        {
            const char *what() const throw();
        };
        class CannotReadFileExeption:public std::exception
        {
            const char *what() const throw();
        };
};

#endif