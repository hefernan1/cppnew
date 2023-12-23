#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
	public :
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		virtual	~PresidentialPardonForm();

		PresidentialPardonForm &	operator=(PresidentialPardonForm const & rhs);

		virtual	 void		execute(Bureaucrat const & executor) const;
	private :
		
};