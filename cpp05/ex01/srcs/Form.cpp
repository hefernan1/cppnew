#include "Form.hpp"

Form::Form(void) : _name("RandomForm"), _signed(false), _toSign(150), _toExec(150)
{
		std::cout << getName() << ", Form has been created with a Sign grade of " << getGradeSign() << std::endl;
}

Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _signed(false), _toSign(gradeSign), _toExec(gradeExec)
{
	if (gradeSign < 1)
		throw Form::GradeTooHighException();
	if (gradeSign > 150)
		throw Form::GradeTooLowException();
	if (gradeExec < 1)
		throw Form::GradeTooHighException();
	if (gradeExec > 150)
		throw Form::GradeTooLowException();
	std::cout << getName() << ", Form has been created with a Sign grade of " << getGradeSign() << 
		" and a Execution grade of " << getGradeExecute() << std::endl;
}

Form::Form(Form const & src) : _name(src.getName()), _signed(src.getSigned()),  _toSign(src.getGradeSign()), _toExec(src.getGradeExecute())
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form(void)
{
	std::cout << getName() << " Form has been destroyed" << std::endl;
}


Form &	Form::operator=(Form const & rhs)
{
	std::cout << "Form assignation operator called" << std::endl;
	if (this != &rhs)
	{
		_signed = rhs.getSigned();
	}
	return (*this);
}

std::string		Form::getName(void) const
{
	return (this->_name);
}

bool			Form::getSigned(void) const
{
	return (this->_signed);
}

int				Form::getGradeExecute(void) const
{
	return (this->_toExec);
}

int				Form::getGradeSign(void) const
{
	return (this->_toSign);
}

void			Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() <= getGradeSign())
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

const char * Form::GradeTooHighException::what() const throw() 
{
	return("Form GradeTooHighException");
}

const char * Form::GradeTooLowException::what() const throw() 
{
	return("Form GradeTooLowException");
}

std::ostream &	operator<<(std::ostream & o, Form const & rhs)
{
	o << "Form name : "<< rhs.getName() << std::endl <<"Signature status : " << (rhs.getSigned() ? "Signed" : "Not signed") << std::endl << "Sign grade : " << rhs.getGradeSign() << std::endl << "Execute grade : " << rhs.getGradeExecute() << std::endl;
	return (o);
}
