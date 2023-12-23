#include "AForm.hpp"

AForm::AForm(void) : _name("RandomForm"), _signed(false), _toSign(150), _toExec(150)
{
		std::cout << getName() << ", Form has been created with a Sign grade of " << getGradeSign() << std::endl;
}

AForm::AForm(std::string name, int gradeSign, int gradeExec) : _name(name), _signed(false), _toSign(gradeSign), _toExec(gradeExec)
{
	if (gradeSign < 1)
		throw AForm::GradeTooHighException();
	if (gradeSign > 150)
		throw AForm::GradeTooLowException();
	if (gradeExec < 1)
		throw AForm::GradeTooHighException();
	if (gradeExec > 150)
		throw AForm::GradeTooLowException();
	std::cout << getName() << ", Form has been created with a Sign grade of " << getGradeSign() << " and an Exec grade of "
	 << getGradeExecute() << std::endl;
}

AForm::AForm(AForm const & src) : _name(src.getName()), _signed(src.getSigned()),  _toSign(src.getGradeSign()), _toExec(src.getGradeExecute())
{
	std::cout << "Form copy constructor called" << std::endl;
}

AForm::~AForm(void)
{
	std::cout << getName() << " Form has been destroyed" << std::endl;
}


AForm &	AForm::operator=(AForm const & rhs)
{
	std::cout << "Form assignation operator called" << std::endl;
	if (this != &rhs)
	{
		_signed = rhs.getSigned();
	}
	return (*this);
}

std::string		AForm::getName(void) const
{
	return (this->_name);
}

bool			AForm::getSigned(void) const
{
	return (this->_signed);
}

int				AForm::getGradeExecute(void) const
{
	return (this->_toExec);
}

int				AForm::getGradeSign(void) const
{
	return (this->_toSign);
}

std::string	AForm::getTarget(void) const
{
	return (this->_target);
}

void			AForm::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() <= getGradeSign())
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw AForm::UnsignedException();
	if (executor.getGrade() > this->getGradeExecute())
		throw AForm::GradeTooLowException();
}

const char * AForm::GradeTooHighException::what() const throw() 
{
	return("Form GradeTooHighException");
}

const char * AForm::GradeTooLowException::what() const throw() 
{
	return("Form GradeTooLowException");
}

const char * AForm::UnsignedException::what() const throw() 
{
	return("Form UnsignedException");
}

std::ostream &	operator<<(std::ostream & o, AForm const & rhs)
{
	o << "Form name : "<< rhs.getName() << std::endl << "Target : " << rhs.getTarget() << std::endl << "Signature status : " << (rhs.getSigned() ? "Signed" : "Not signed") << std::endl << "Sign grade : " << rhs.getGradeSign() << std::endl << "Execute grade : " << rhs.getGradeExecute() << std::endl;
	return (o);
}
