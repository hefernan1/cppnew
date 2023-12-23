#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = "";
	std::cout << "ShrubberyCreationForm has been created with a Sign grade of 145 and execute grade 137" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = target;
	std::cout << "ShrubberyCreationForm has been created with [" << this->getTarget() << "] as target" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
{
	*this = src;
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm has been destroyed" << std::endl;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw AForm::UnsignedException();
	else if (executor.getGrade() > this->getGradeExecute())
		throw AForm::GradeTooLowException();
	else
	{
		std::string		outName(this->_target + "_shrubbery");
		std::ofstream	file(outName.c_str());
		if (file)
		{
			file << "      .     .  .      +     .      .          ." << std::endl;
			file << "     .       .      .     #       .           ." << std::endl;
			file << "        .      .         ###            .      .      ." << std::endl;
			file << "      .      .   \"#:. .:##\"##:. .:#\"  .      ." << std::endl;
			file << "          .      . \"####\"###\"####\"  ." << std::endl;
			file << "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       ." << std::endl;
			file << "  .             \"#########\"#########\"        .        ." << std::endl;
			file << "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       ." << std::endl;
			file << "     .     .  \"#######\"\"##\"##\"\"#######\"                  ." << std::endl;
			file << "                .\"##\"#####\"#####\"##\"           .      ." << std::endl;
			file << "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     ." << std::endl;
			file << "      .     \"#######\"##\"#####\"##\"#######\"      .     ." << std::endl;
			file << "    .    .     \"#####\"\"#######\"\"#####\"    .      ." << std::endl;
			file << "            .     \"      000      \"    .     ." << std::endl;
			file << "       .         .   .   000     .        .       ." << std::endl;
		}
		else
			std::cout << "Error while opening file" << std::endl;
	}
}