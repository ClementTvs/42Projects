CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = harl2_0
SRC = main.cpp Harl.cpp

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all