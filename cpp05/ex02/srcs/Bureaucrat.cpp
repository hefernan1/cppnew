#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void) : _name("Null"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl; 
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << getName() << ", Bureaucrat grade [" << getGrade() << "] has been created" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	*this = src;
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << getName() << ", Bureaucrat has been destroyed" << std::endl;
}

const char * Bureaucrat::GradeTooHighException::what() const throw() 
{
	return("Bureaucrat GradeTooHighException");
}

const char * Bureaucrat::GradeTooLowException::what() const throw() 
{
	return("Bureaucrat GradeTooLowException");
}

int 	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}
std::string		Bureaucrat::getName(void) const
{
	return (this->_name);
}

void	Bureaucrat::gradeUp(void)
{
	this->_grade--;
	if(this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "Bureaucrat " << this->_name << " has been promoted to grade : [" << this->_grade << "], previously was grade : [" << this->_grade + 1 << "]." << std::endl;
		
}

void	Bureaucrat::gradeDown(void)
{
	this->_grade++;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat " << this->_name << " has been promoted to grade : [" << this->_grade << "], previously was grade : [" << this->_grade - 1 << "]." << std::endl;

}

void	Bureaucrat::signForm(AForm & form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " execute " << form.getName() << " with success" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const & rhs)
{
	std::cout << "Bureaucrat Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_grade = rhs._grade;
	}
	return(*this);
}

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & rhs)
{
	o << rhs.getName() << ", Bureaucrat grade " << rhs.getGrade() << "." << std::endl;
	return (o);
}