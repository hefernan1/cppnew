#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


class	Intern
{
	public :
		Intern(void);
		Intern(Intern const & src);
		~Intern();

		class WrongFormNameException : public std::exception
		{
			public :
				virtual const char * what() const throw();
		};
		
		AForm *	makeForm(std::string formName, std::string target);
		Intern &	operator=(Intern const & rhs);

	private :
		AForm *_createPresidentialForm(std::string target);
		AForm *_createRobotomyForm(std::string target);
		AForm *_createShrubberyForm(std::string target);
};
