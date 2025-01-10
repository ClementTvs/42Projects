# Compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Répertoires
SRCDIR = src
OBJDIR = obj
INCDIR = include
LIBFTDIR = libft
MLXDIR = minilibx-linux

# Fichiers sources et objets
SRC = 	$(SRCDIR)/core.c \
	$(SRCDIR)/render.c \

OBJ = 	$(OBJDIR)/core.o \
 	$(OBJDIR)/render.o \

# Librairies
LIBFT = $(LIBFTDIR)/libft.a
MLX = $(MLXDIR)/libmlx.a

# Exécutable
NAME = so_long

# Compilation de l'exécutable
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFTDIR) -L$(MLXDIR) -lftprintf -lmlx -lXext -lX11 -o $(NAME)

# Compilation des objets
$(OBJDIR)/render.o: $(SRCDIR)/render.c $(INCDIR)/so_long.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(MLXDIR) -c $< -o $@

$(OBJDIR)/core.o: $(SRCDIR)/core.c $(INCDIR)/so_long.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(MLXDIR) -c $< -o $@

# Compilation de libft
$(LIBFT):
	make -C $(LIBFTDIR)

# Compilation de minilibx
$(MLX):
	make -C $(MLXDIR)

# Nettoyage
clean:
	rm -rf $(OBJDIR)
	make clean -C $(LIBFTDIR)
	make clean -C $(MLXDIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR)

re: fclean all

