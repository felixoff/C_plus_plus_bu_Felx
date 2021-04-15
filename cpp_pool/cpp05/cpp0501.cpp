#include<iostream>
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
    private:
        std::string const name;
        bool is_sign;
        int const grade_sign;
        int const grade_run;
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
        class GradeTooHighException:public std::exception
        {
            const char *what() const noexcept;
        };
        class GradeTooLowException:public std::exception
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

void Bureaucrat::signForm(Form &form) const
{
    if (this->getGrade() > form.getGradeSign())
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
    this->is_sign = true;
}

int main(void)
{
	Bureaucrat francis("Francis", 100);
	std::cout << francis << std::endl;

	Form form1("Taxes", 100, 50);
	std::cout << form1 << std::endl;
	form1.beSigned(francis);
	std::cout << form1 << std::endl;

	std::cout << "---" << std::endl;

	Form form2("NDA", 99, 50);
	std::cout << form2 << std::endl;
    try
    {
        francis.signForm(form2);
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() <<std::endl;
    }
	std::cout << form2 << std::endl;

	std::cout << "---" << std::endl;

	Form form3("Other Paper", 101, 50);
	std::cout << form3 << std::endl;
	francis.signForm(form3);
	std::cout << form3 << std::endl;
	try
	{
		francis.signForm(form3);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << form3 << std::endl;

	std::cout << "---" << std::endl;

	try
	{
		Form formException("NDA", 99, 50);
		std::cout << formException << std::endl;
		formException.beSigned(francis);
		std::cout << formException << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	try
	{
		Form formException("Important Form", 1000, 50);
		std::cout << formException << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	try
	{
		Form formException("Important Form", 0, 50);
		std::cout << formException << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	try
	{
		Form formException("Important Form", 100, 1000);
		std::cout << formException << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	try
	{
		Form formException("Important Form", 100, 0);
		std::cout << formException << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
