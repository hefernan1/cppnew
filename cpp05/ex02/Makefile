NAME	=	Aforms

SRCS		=	main.cpp \
					srcs/Bureaucrat.cpp \
					srcs/AForm.cpp \
					srcs/ShrubberyCreationForm.cpp \
					srcs/RobotomyRequestForm.cpp \
					srcs/PresidentialPardonForm.cpp

OBJS		=	$(SRCS:.cpp=.o)

CXX			=	c++ 

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -I./Includes

all:			$(NAME)

%.o: %.cpp
				$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME) :		$(OBJS)
					$(CXX) $(CXXFLAGS) $(OBJS) -o $@

clean :
				rm -f $(OBJS) 

fclean :	clean
				rm -f $(NAME) *_shrubbery

re :		fclean all

.PHONY : all clean fclean re