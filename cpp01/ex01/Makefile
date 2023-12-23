NAME = Zombie
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Zombie.cpp main.cpp zombieHorde.cpp
OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -fr $(OBJ)

fclean:
	make clean
	rm -fr $(NAME)

re: fclean all

.PHONY: all clean fclean re