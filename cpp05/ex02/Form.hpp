#ifndef FORM_H
#define FORM_H
#include<iostream>
#include<fstream>
class Form;
#include "Bureaucrat.hpp"
class Form
{
    protected:
        std::string name;
        bool is_sign;
        int  grade_sign;
        int  grade_run;
        Form();
    public:
        Form(std::string const &name, int  grade_sign, int grade_run);
        Form(const Form &other);
        virtual ~Form();
        Form &operator =(const Form &other);
        std::string const getName() const;
        int getGradeRun() const;
        int getGradeSign() const;
        bool getIsSign() const;
        void beSigned(Bureaucrat const &buro);
        virtual void execute(Bureaucrat const & executor) const = 0;
        class GradeTooHighException:public std::exception
        {
            const char *what() const throw();
        };
        class GradeTooLowException:public std::exception
        {
            const char *what() const throw();
        };
        class FormAlreadySigned:public std::exception
        {
            const char *what() const throw();
        };
};


std::ostream &operator <<(std::ostream &output, Form const &other);
#endif