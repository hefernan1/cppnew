NAME	=	Convert

SRCS		=	main.cpp \
					srcs/ScalarConverter.cpp

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
				rm -f $(NAME)

re :		fclean all

.PHONY : all clean fclean re