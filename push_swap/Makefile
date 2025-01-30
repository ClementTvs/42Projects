# Compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Répertoires
SRCDIR = src
OBJDIR = obj
INCDIR = include
LIBFTDIR = libft

# Fichiers sources et objets
SRC = 	$(SRCDIR)/main.c \
	$(SRCDIR)/push_utils.c \
	$(SRCDIR)/push.c \
	$(SRCDIR)/reverse_rotate.c \
	$(SRCDIR)/rotate.c \
	$(SRCDIR)/swap.c \
	$(SRCDIR)/init_a.c \
	$(SRCDIR)/init_b.c \
	$(SRCDIR)/init_stack.c \
	$(SRCDIR)/sort_stack.c \
	$(SRCDIR)/errors.c \
	$(SRCDIR)/split.c \

OBJ = 	$(OBJDIR)/main.o \
	$(OBJDIR)/push_utils.o \
	$(OBJDIR)/push.o \
	$(OBJDIR)/reverse_rotate.o \
	$(OBJDIR)/rotate.o \
	$(OBJDIR)/swap.o \
	$(OBJDIR)/init_a.o \
	$(OBJDIR)/init_b.o \
	$(OBJDIR)/init_stack.o \
	$(OBJDIR)/sort_stack.o \
	$(OBJDIR)/errors.o \
	$(OBJDIR)/split.o \

# Librairies
LIBFT = $(LIBFTDIR)/libftprintf.a

# Exécutable
NAME = push_swap

# Compilation de l'exécutable
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFTDIR) -lftprintf -o $(NAME) -g

# Compilation des objets
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/push_swap.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Compilation de libft
$(LIBFT):
	make -C $(LIBFTDIR)

# Nettoyage
clean:
	rm -rf $(OBJDIR)
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR)

re: fclean all
