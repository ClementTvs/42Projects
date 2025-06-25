CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = phonebook
SRC = PhoneBook.cpp Contact.cpp main.cpp

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all