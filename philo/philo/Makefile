CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCDIR = src/
OBJDIR = obj/

SRC_FILES = main utils
SRC = $(addprefix $(SRCDIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJDIR), $(addsuffix .o, $(SRC_FILES)))
NAME = philo

G = \033[1;92m
RST = \033[0m

all : $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$GCompilation done!$(RST)"

$(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$GCompiling..$(RST)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)
	@echo "$GCleaned obj files$(RST)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$GAll cleaned$(RST)"

re: fclean all
	@echo "$GCleaned and compiled$(RST)"

.PHONY: all clean fclean re
