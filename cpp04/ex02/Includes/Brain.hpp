#pragma once

# include <iostream>
# include <string>

class Brain
{
	public:
		Brain();
		Brain( Brain const & src );
		~Brain();

		void	printIdeas(void);
		Brain &	operator=( Brain const & rhs );
		std::string	_ideas[100];
};