#include<iostream>

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

int main()
{
	Bureaucrat francis("Francis", 100);
	std::cout << francis << std::endl;
	francis.gradeInc();
	std::cout << francis << std::endl;
	francis.gradeDesc();
	std::cout << francis << std::endl;

	try
	{
		Bureaucrat jack("Jack", 0);
		std::cout << jack << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat jack("Jack", 1000);
		std::cout << jack << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat jack("Jack", 1);
		std::cout << jack << std::endl;
		jack.gradeInc();
		std::cout << jack << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat jack("Jack", 150);
		std::cout << jack << std::endl;
		jack.gradeDesc();
		std::cout << jack << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}