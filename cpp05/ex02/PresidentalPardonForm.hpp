#ifndef PRESIDENTALPARDONFORM_H
#define PRESIDENTALPARDONFORM_H
#include "Form.hpp"
#include "Bureaucrat.hpp"
class PresidentialPardonForm :public Form
{
    private:
        std::string &target;
        PresidentialPardonForm();
    public:
        PresidentialPardonForm(std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        ~PresidentialPardonForm();
        PresidentialPardonForm &operator =(PresidentialPardonForm &other);
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
};
#endif