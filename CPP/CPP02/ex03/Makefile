CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = BSP
SRC = main.cpp Fixed.cpp bsp.cpp Point.cpp

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all