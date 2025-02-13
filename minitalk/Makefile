# Nom des exécutables
NAMESERV = server
NAMECLIENT = client

# Dossiers des fichiers sources
SRC_DIR = src
OBJ_DIR = obj
FT_PRINTF_DIR = ft_printf

FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

# Fichiers sources
SRCSSERV = $(SRC_DIR)/utils.c $(SRC_DIR)/server.c
SRCSCLIENT = $(SRC_DIR)/utils.c $(SRC_DIR)/client.c

# Fichiers objets
OBJSERV = $(SRCSSERV:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJSCLIENT = $(SRCSCLIENT:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compilateur et flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Règles par défaut
all: $(NAMESERV) $(NAMECLIENT)

# Créer l'exécutable du serveur
$(NAMESERV): $(OBJSERV)
	$(CC) $(OBJSERV) $(FT_PRINTF_LIB) -o $(NAMESERV)

# Créer l'exécutable du client
$(NAMECLIENT): $(OBJSCLIENT)
	$(CC) $(OBJSCLIENT) $(FT_PRINTF_LIB) -o $(NAMECLIENT)

# Créer les fichiers objets à partir des sources (serveur)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyer les fichiers objets et l'exécutable
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAMESERV) $(NAMECLIENT)

# Recompiler le projet entièrement
re: fclean all

# Lancer les exécutables
run: all
	./$(NAMESERV)
	./$(NAMECLIENT)

.PHONY: all clean fclean re run
