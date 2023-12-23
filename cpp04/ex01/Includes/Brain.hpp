#pragma once

# include <iostream>
# include <string>

class Brain
{
	public:
		Brain();
		Brain( Brain const & src );
		~Brain();
		std::string	_ideas[100];

		void	printIdeas(void);
		Brain &		operator=( Brain const & rhs );

};