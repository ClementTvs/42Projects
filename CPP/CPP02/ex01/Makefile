CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Fixed
SRC = main.cpp Fixed.cpp
TEST = test.cpp Fixed.cpp

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

test:
	@$(CC) $(CFLAGS) $(TEST) -o $(NAME)_test

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all