#include "ShrubberyCreationForm.hpp"

std::string const ShrubberyCreationForm::trees[3] = {
	"      /\\\n" \
	"     /\\*\\\n" \
	"    /\\O\\*\\\n" \
	"   /*/\\/\\/\\\n" \
	"  /\\O\\/\\*\\/\\\n" \
	" /\\*\\/\\*\\/\\/\\\n" \
	"/\\O\\/\\/*/\\/O/\\\n" \
	"      ||\n" \
	"      ||\n" \
	"      ||\n",
	"         v\n" \
	"        >X<\n" \
	"         A\n" \
	"        d$b\n" \
	"      .d\\$$b.\n" \
	"    .d$i$$\\$$b.\n" \
	"       d$$@b\n" \
	"      d\\$$$ib\n" \
	"    .d$$$\\$$$b\n" \
	"  .d$$@$$$$\\$$ib.\n" \
	"      d$$i$$b\n" \
	"     d\\$$$$@$b\n" \
	"  .d$@$$\\$$$$$@b.\n" \
	".d$$$$i$$$\\$$$$$$b.\n" \
	"        ###\n" \
	"        ###\n" \
	"        ###\n",
	"         *\n" \
	"        /|\\\n" \
	"       /*|O\\\n" \
	"      /*/|\\*\\\n" \
	"     /X/O|*\\X\\\n" \
	"    /*/X/|\\X\\*\\\n" \
	"   /O/*/X|*\\O\\X\\\n" \
	"  /*/O/X/|\\X\\O\\*\\\n" \
	" /X/O/*/X|O\\X\\*\\O\\\n" \
	"/O/X/*/O/|\\X\\*\\O\\X\\\n" \
	"        |X|\n" \
	"        |X|\n"
};

ShrubberyCreationForm::ShrubberyCreationForm(std::string &target):Form("shrub",145,137),target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):\
Form(other.name,other.grade_sign, other.grade_run),target(other.target)
{
}
    
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator =(ShrubberyCreationForm &other)
{
    this->target = other.target;
    this->name = other.name;
    this->grade_run = other.grade_run;
    this->grade_sign = other.grade_sign;
    return *this;
}

std::string const ShrubberyCreationForm::getTarget() const
{
    return this->target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->grade_run)
        throw GradeTooLowExceptionToExec();
    if (this->is_sign == false)
        throw FormNotSigned();
    std::ofstream fout;
    std::string fileName = "<"+this->target+">_shrubbery";
    fout.open(fileName);
    if (fout.is_open())
    {
        fout<<this->trees[rand() % 3];
        if (fout.bad())
            {
                fout<< std::endl;
                fout.close();
                throw CannotReadFileExeption();
            }
        fout<< std::endl;
        fout.close();
    }
    else
        throw CannotOpenFileExeption();
}

const char *ShrubberyCreationForm::FormNotSigned::what() const throw()
{
    return "ShrubberyCreationForm::FormNotSigned";
}

const char *ShrubberyCreationForm::GradeTooLowExceptionToExec::what() const throw()
{
    return "ShrubberyCreationForm::GradeTooLowExceptionToExec";
}

const char *ShrubberyCreationForm::CannotOpenFileExeption::what() const throw()
{
    return "ShrubberyCreationForm::CannotOpenFileExeption";
}

const char *ShrubberyCreationForm::CannotReadFileExeption::what() const throw()
{
    return "ShrubberyCreationForm::CannotReadFileExeption";
}
