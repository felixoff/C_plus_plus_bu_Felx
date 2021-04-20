
#include "PresidentalPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string &target):Form("prsidento",25,5),target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):\
Form(other.name,other.grade_sign, other.grade_run),target(other.target)
{
}
    
PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator =(PresidentialPardonForm &other)
{
    this->target = other.target;
    this->name = other.name;
    this->grade_run = other.grade_run;
    this->grade_sign = other.grade_sign;
    return *this;
}

std::string const PresidentialPardonForm::getTarget() const
{
    return this->target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->grade_run)
        throw GradeTooLowExceptionToExec();
    if (this->is_sign == false)
        throw FormNotSigned();
    std::cout << "<" << this->target << "> has been pardoned by Zafod Beeblebrox." <<std::endl;  
}

const char *PresidentialPardonForm::FormNotSigned::what() const throw()
{
    return "PresidentialPardonForm::FormNotSigned";
}

const char *PresidentialPardonForm::GradeTooLowExceptionToExec::what() const throw()
{
    return "PresidentialPardonForm::GradeTooLowExceptionToExec";
}