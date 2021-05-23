#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat::GradeTooLowException";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat::GradeTooHighException";
}
Bureaucrat::Bureaucrat(std::string const &name, int grade):name(name),grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):name(other.name),grade(other.grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &other)
{
    this->name = other.name;
    this->grade = other.grade;
    return *this;
}

std::string const Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::gradeInc()
{
    if (this->getGrade() - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->getGrade() - 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade--;
}

void Bureaucrat::gradeDesc()
{
    if (this->getGrade() + 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->getGrade() + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

std::ostream &operator <<(std::ostream &output, Bureaucrat const &other)
{
    output << "bureaucrat <"<<other.getName()<<">, bureaucrat grade <"<< other.getGrade() <<">." << std::endl;
    return output;
}
