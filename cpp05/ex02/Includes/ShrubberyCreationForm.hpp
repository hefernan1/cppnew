#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm
{
	public :
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		virtual	~ShrubberyCreationForm();

		ShrubberyCreationForm &	operator=(ShrubberyCreationForm const & rhs);

		virtual	 void		execute(Bureaucrat const & executor) const;
	private :
		
};