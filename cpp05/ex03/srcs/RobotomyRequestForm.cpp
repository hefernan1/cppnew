#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = "";
	std::cout << "RobotomyRequestForm has been created with a Sign grade of 72 and execute grade 45" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
	std::cout << "RobotomyRequestForm has been created with [" << this->getTarget() << "] as target" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
{
	*this = src;
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm has been destroyed" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	srand (time(NULL));
	int random = rand() % 2;
	if (this->getSigned() == false)
		throw AForm::UnsignedException();
	else if (executor.getGrade() > this->getGradeExecute())
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << random << std::endl;
		std::cout << "*Drilling noises*" << std::endl;
		if (random % 2 == 0)
			std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
		else
			std::cout << this->getTarget() << " has failed to be robotomized" << std::endl;
	}
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return (*this);
}