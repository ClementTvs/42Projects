# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctravers <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 13:03:53 by ctravers          #+#    #+#              #
#    Updated: 2024/11/16 11:17:43 by ctravers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
INCLUDE = include
LIBFT = libft
SRC_DIR = src/
OBJ_DIR = obj/
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I
AR = ar rcs

SRC_FILES = ft_printf ft_printf2

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF = .cache_exists

all: $(NAME)

$(NAME): $(OBJ)
		@make -C $(LIBFT)
		@cp libft/libft.a .
		@mv libft.a $(NAME)
		@$(AR) $(NAME) $(OBJ)
		@echo "Compilation Done"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
		@echo "Compiling .."
		@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
		@mkdir -p $(OBJ_DIR)

clean:
		@rm -rf $(OBJ_DIR)
		@make clean -C $(LIBFT)
		@echo "Object files cleaned"

fclean: clean
		@rm -f $(NAME)
		@rm -f $(LIBFT)/libft.a
		@echo "All clean"

re: fclean all
	@echo "Cleaned and rebuilt"

.PHONY:	all clean fclean re
