#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm
{
	public :
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		virtual	~RobotomyRequestForm();

		RobotomyRequestForm &	operator=(RobotomyRequestForm const & rhs);

		virtual	 void		execute(Bureaucrat const & executor) const;
	private :
		
};