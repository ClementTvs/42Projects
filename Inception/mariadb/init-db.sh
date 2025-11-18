#!/bin/bash
set -e

# Démarre MariaDB temporairement pour l'initialisation
echo "🚀 Initialisation de MariaDB..."
mysqld_safe --skip-networking &
pid="$!"

# Attend que le serveur soit prêt
until mysqladmin ping &>/dev/null; do
  sleep 1
done

# Configure la base, l'utilisateur et les droits
echo "⚙️ Configuration de la base '${MYSQL_DATABASE}'..."
mysql -u root <<-EOSQL
    CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
    CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
    GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
    FLUSH PRIVILEGES;
EOSQL

# Stoppe le processus d'initialisation
mysqladmin shutdown
wait "$pid"

echo "✅ MariaDB initialisé. Démarrage normal..."
exec mysqld_safe
