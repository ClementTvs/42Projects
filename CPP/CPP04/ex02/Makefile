CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = AAnimalsAndTheirBrains
SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongCat.cpp WrongAnimal.cpp Brain.cpp
DEBUG_FLAGS = -g -DDEBUG

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

debug:
	@$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(SRC) -o $(NAME)
	@echo "Compiled with debug mode"

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all debug clean fclean re