#include "Form.hpp"

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form::GradeTooLowException";
}

const char *Form::FormAlreadySigned::what() const throw()
{
    return "Form::FormAlreadySigned";
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form::GradeTooHighException";
}

Form::Form(std::string const &name, int  grade_sign, int grade_run):\
name(name),is_sign(false),grade_sign(grade_sign),grade_run(grade_run)
{
    if (grade_sign < 1)
        throw Form::GradeTooHighException();
    if (grade_sign > 150)
        throw Form::GradeTooLowException();
    if (grade_run < 1)
        throw Form::GradeTooHighException();
    if (grade_run > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &other):name(other.name),grade_sign(other.grade_sign),grade_run(other.grade_run)
{
    this->is_sign = other.is_sign;
    if (grade_sign < 1)
        throw Form::GradeTooHighException();
    if (grade_sign > 150)
        throw Form::GradeTooLowException();
    if (grade_run < 1)
        throw Form::GradeTooHighException();
    if (grade_run > 150)
        throw Form::GradeTooLowException();
}

Form::~Form()
{
}

Form &Form::operator = (const Form &other)
{
    this->is_sign = other.is_sign;
    return *this;
}

std::string const Form::getName() const
{
    return this->name;
}

int Form::getGradeSign() const
{
    return this->grade_sign;
}

int Form::getGradeRun() const
{
    return this->grade_run;
}

bool Form::getIsSign() const
{
    return this->is_sign;
}

std::ostream &operator <<(std::ostream &output, Form const &other)
{
    output << "Form <"<<other.getName()<<">, Form grade_sign <"<< other.getGradeSign() \
     <<">, Form grade run <" << other.getGradeRun() << ">, Form is signed <" <<\
     other.getIsSign() << ">"<< std::endl;
    return output;
}

void Form::beSigned(Bureaucrat const &buro)
{
    if (buro.getGrade() > this->getGradeSign())
        throw Form::GradeTooLowException();
    if (this->is_sign == true)
        throw Form::FormAlreadySigned();
    this->is_sign = true;
}