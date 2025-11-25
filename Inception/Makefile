COMPOSE = docker compose
ENV_FILE = .env
DATA_DIR = /home/ctravers/data

all: build up

check-env:
	@if [ ! -f $(ENV_FILE) ]; then \
		echo "❌ Erreur: Le fichier .env n'existe pas !"; \
		exit 1; \
	fi

build: check-env create-dirs
	@echo "🔨 Construction des images Docker..."
	$(COMPOSE) build

up: check-env create-dirs
	@echo "🚀 Démarrage des services..."
	$(COMPOSE) up -d
	@echo "✅ Services démarrés !"
	@echo "🌐 Accède à https://ctravers.42.fr"

down:
	@echo "🛑 Arrêt des services..."
	$(COMPOSE) down

clean: down
	@echo "🧹 Nettoyage des containers et réseaux..."
	docker system prune -f

fclean: down
	@echo "💣 Suppression complète (containers, volumes, images)..."
	$(COMPOSE) down -v --rmi all
	docker system prune -af --volumes
	@echo "🗑️  Suppression des données..."
	@sudo rm -rf $(DATA_DIR)/mariadb $(DATA_DIR)/wordpress

re: fclean all

logs:
	$(COMPOSE) logs -f

status:
	@echo "📊 Statut des services:"
	docker ps --filter "name=nginx" --filter "name=wordpress" --filter "name=mariadb"

logs-nginx:
	$(COMPOSE) logs -f nginx

logs-wordpress:
	$(COMPOSE) logs -f wordpress

logs-mariadb:
	$(COMPOSE) logs -f mariadb

.PHONY: all build up down clean fclean re logs status create-dirs