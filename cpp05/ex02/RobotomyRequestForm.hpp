#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H
#include "Form.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm :public Form
{
    private:
        std::string &target;
        RobotomyRequestForm();
    public:
        RobotomyRequestForm(std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        ~RobotomyRequestForm();
        RobotomyRequestForm &operator =(RobotomyRequestForm &other);
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