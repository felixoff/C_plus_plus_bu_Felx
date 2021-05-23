#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string &target):Form("robotom",72,45),target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):\
Form(other.name,other.grade_sign, other.grade_run),target(other.target)
{
}
    
RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator =(RobotomyRequestForm &other)
{
    this->target = other.target;
    this->name = other.name;
    this->grade_run = other.grade_run;
    this->grade_sign = other.grade_sign;
    return *this;
}

std::string const RobotomyRequestForm::getTarget() const
{
    return this->target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->grade_run)
        throw GradeTooLowExceptionToExec();
    if (this->is_sign == false)
        throw FormNotSigned();
    std::cout << "DRRRRRRR DRRRRRRRR DRRRRRRR" <<std::endl;
    if (rand() % 100 >= 50)
        std::cout << "<" << this->target << "> has been robotomized successfully 50% of the time" <<std::endl;  
    else
            std::cout << "<" << this->target << "> has been robotomized failure 50% of the time" <<std::endl;  
}

const char *RobotomyRequestForm::FormNotSigned::what() const throw()
{
    return "RobotomyRequestForm::FormNotSigned";
}

const char *RobotomyRequestForm::GradeTooLowExceptionToExec::what() const throw()
{
    return "RobotomyRequestForm::GradeTooLowExceptionToExec";
}
