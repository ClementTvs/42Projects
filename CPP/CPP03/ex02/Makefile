CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = FragTrap
SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all