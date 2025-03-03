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
	$(SRCDIR)/utils.c \
	$(SRCDIR)/check_map_content.c \
	$(SRCDIR)/check_map_format.c \
	$(SRCDIR)/playermouv.c \

OBJ = 	$(OBJDIR)/core.o \
 	$(OBJDIR)/render.o \
 	$(OBJDIR)/utils.o \
 	$(OBJDIR)/check_map_content.o \
 	$(OBJDIR)/check_map_format.o \
 	$(OBJDIR)/playermouv.o \

# Librairies
LIBFT = $(LIBFTDIR)/libftprintf.a
MLX = $(MLXDIR)/libmlx.a

# Exécutable
NAME = so_long

# Compilation de l'exécutable
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFTDIR) -L$(MLXDIR) -lftprintf -lmlx -lXext -lX11 -o $(NAME)
	@echo "Compilation Done"

# Compilation des objets
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/so_long.h
	@echo "Compiling .."
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(MLXDIR) -c $< -o $@

# Compilation de libft
$(LIBFT):
	@make -C $(LIBFTDIR)

# Compilation de minilibx
$(MLX):
	@make -C $(MLXDIR)

# Nettoyage
clean:
	@rm -rf $(OBJDIR)
	@make clean -C $(LIBFTDIR)
	@make clean -C $(MLXDIR)
	@echo "Object files cleaned"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFTDIR)
	@echo "All clean"

re: fclean all
	@echo "Cleaned and rebuilt"

.PHONY: all clean re fclean
