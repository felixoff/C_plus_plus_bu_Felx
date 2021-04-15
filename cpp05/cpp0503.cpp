#include<iostream>
#include<fstream>
class Form;
class Bureaucrat
{
    private:
        std::string name;
        int grade;
        Bureaucrat();
    public:
        Bureaucrat(std::string const &name, int grade);
        Bureaucrat(const Bureaucrat &other);
        virtual ~Bureaucrat();
        Bureaucrat &operator =(const Bureaucrat &other);
        std::string const getName() const;
        int getGrade() const;
        void gradeInc();
        void gradeDesc();
        void signForm(Form &form) const;
        std::string const getTarget() const;
        void executeForm(Form const & form);
        class GradeTooHighException:public std::exception
        {
            const char *what() const noexcept;
        };
        class GradeTooLowException:public std::exception
        {
            const char *what() const noexcept;
        };
};

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
            const char *what() const noexcept;
        };
        class GradeTooLowException:public std::exception
        {
            const char *what() const noexcept;
        };
        class FormAlreadySigned:public std::exception
        {
            const char *what() const noexcept;
        };
};

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
    return "Bureaucrat::GradeTooLowException";
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept
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
void Bureaucrat::executeForm(Form const & form)
{
if (this->getGrade() <=  form.getGradeRun() && form.getIsSign() == false)
        std::cout <<  "<" << this->getName() << "> executes <" << form.getName() <<">" << std::endl;
    else 
        std::cout <<  "<" <<this->getName() <<"> cannot execute <" << \
        form.getName() <<">" << std::endl;
    
    form.execute(*this);
}

void Bureaucrat::signForm(Form &form) const
{
    if (this->getGrade() <= form.getGradeSign() && form.getIsSign() == false)
        std::cout <<  "<" << this->getName() << "> signs <" << form.getName() <<">" << std::endl;
    else 
        std::cout <<  "<" <<this->getName() <<"> cannot sign <" << \
        form.getName() <<"> because <his grade is too low>" << std::endl;
    
    form.beSigned(*this);
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

const char *Form::GradeTooLowException::what() const noexcept
{
    return "Form::GradeTooLowException";
}

const char *Form::FormAlreadySigned::what() const noexcept
{
    return "Form::FormAlreadySigned";
}

const char *Form::GradeTooHighException::what() const noexcept
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
            const char *what() const noexcept;
        };
        class GradeTooLowExceptionToExec:public std::exception
        {
            const char *what() const noexcept;
        };
        class CannotOpenFileExeption:public std::exception
        {
            const char *what() const noexcept;
        };
        class CannotReadFileExeption:public std::exception
        {
            const char *what() const noexcept;
        };
};

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

const char *ShrubberyCreationForm::FormNotSigned::what() const noexcept
{
    return "ShrubberyCreationForm::FormNotSigned";
}

const char *ShrubberyCreationForm::GradeTooLowExceptionToExec::what() const noexcept
{
    return "ShrubberyCreationForm::GradeTooLowExceptionToExec";
}

const char *ShrubberyCreationForm::CannotOpenFileExeption::what() const noexcept
{
    return "ShrubberyCreationForm::CannotOpenFileExeption";
}

const char *ShrubberyCreationForm::CannotReadFileExeption::what() const noexcept
{
    return "ShrubberyCreationForm::CannotReadFileExeption";
}

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
            const char *what() const noexcept;
        };
        class GradeTooLowExceptionToExec:public std::exception
        {
            const char *what() const noexcept;
        };
};

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

const char *RobotomyRequestForm::FormNotSigned::what() const noexcept
{
    return "RobotomyRequestForm::FormNotSigned";
}

const char *RobotomyRequestForm::GradeTooLowExceptionToExec::what() const noexcept
{
    return "RobotomyRequestForm::GradeTooLowExceptionToExec";
}

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
            const char *what() const noexcept;
        };
        class GradeTooLowExceptionToExec:public std::exception
        {
            const char *what() const noexcept;
        };
};

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

const char *PresidentialPardonForm::FormNotSigned::what() const noexcept
{
    return "PresidentialPardonForm::FormNotSigned";
}

const char *PresidentialPardonForm::GradeTooLowExceptionToExec::what() const noexcept
{
    return "PresidentialPardonForm::GradeTooLowExceptionToExec";
}

class Intern
{
    public:
        Intern();
        Intern(const Intern &other);
        ~Intern();
        Intern &operator =(Intern &other);
        Form *makeForm(std::string name,std::string target);
        class FormNotExistsException:public std::exception
        {
            const char *what() const noexcept;
        };
};

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
}
    
Intern::~Intern()
{
}

Intern &Intern::operator =(Intern &other)
{
 //   (void)other;
    return *this;
}

Form *Intern::makeForm(std::string name,std::string target)
{
    Form *form;
    if (name == "shrubbery creation")
        form = new ShrubberyCreationForm(target);
    else if (name == "robotomy request")
        form = new RobotomyRequestForm(target);
    else if (name == "presidential pardon")
        form = new PresidentialPardonForm(target);
    else
        throw FormNotExistsException();
    std::cout << "Intern creates <"<< form <<">"<<std::endl;
    return form;
}

const char *Intern::FormNotExistsException::what() const noexcept
{
    return "Intern::FormNotExistsException";
}


int				main(void)
{
	Intern					joe;

	//joe.makeForm("univers creation", "just here");
	Form					*form1 = joe.makeForm("shrubbery creation", "mars");
	Form					*form2 = joe.makeForm("robotomy request", "terre");
	Form					*form3 = joe.makeForm("presidential pardon", "president");
	std::cout << form1;

	try
	{
		Bureaucrat	bob("Bob", 150);
		std::cout << bob;
		bob.signForm(*form1);
		bob.executeForm(*form1);
		std::cout << *form1;
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR Bob" << std::endl;
	}

	try
	{
		Bureaucrat	jack("Jack", 140);
		std::cout << jack;
		jack.signForm(*form1);
		jack.executeForm(*form1);
		std::cout << *form1;
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR Jack" << std::endl;
	}

	try
	{
		Bureaucrat	jule("President", 2);
		std::cout << jule;
		jule.executeForm(*form1);
		std::cout << *form1;

		jule.signForm(*form2);
		jule.executeForm(*form2);
		std::cout << *form2;

		jule.signForm(*form3);
		jule.executeForm(*form3);
		std::cout << *form3;
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR Jule" << std::endl;
	}

	return (0);
}