CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = FormsBureaucratAndInterns
SRC = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShruberryCreationForm.cpp Intern.cpp
DEBUG_FLAGS = -g -DDEBUG

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "Compiling with $(CFLAGS) flags"

debug:
	@$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(SRC) -o $(NAME)
	@echo "Compiled with debug mode"

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all debug clean fclean re