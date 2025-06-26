CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = BraiiinnnzzZ
SRC = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all