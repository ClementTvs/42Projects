CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = MutantStack
SRC = main.cpp

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "Compiling with $(CFLAGS) flags"

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all debug clean fclean re