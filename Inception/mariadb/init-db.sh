#!/bin/bash
set -e

echo "🚀 Initialisation de MariaDB..."

# Initialiser la base de données si nécessaire
if [ ! -d "/home/ctravers/data/mariadb/mysql" ]; then
    echo "📦 Installation de la base système..."
    mysql_install_db --user=mysql --datadir=/home/ctravers/data/mariadb
fi

# Démarrer MariaDB en arrière-plan
echo "🔧 Démarrage temporaire pour configuration..."
mysqld --user=mysql --datadir=/home/ctravers/data/mariadb --skip-networking &
pid="$!"

# Attendre que MySQL soit prêt (max 30 secondes)
for i in {1..30}; do
    if mysqladmin ping --silent 2>/dev/null; then
        echo "✅ MariaDB prêt !"
        break
    fi
    echo "⏳ Attente de MariaDB... ($i/30)"
    sleep 1
done

# Créer la base et l'utilisateur
echo "⚙️ Configuration de la base '${MYSQL_DATABASE}'..."
mysql -u root <<-EOSQL
    CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
    CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
    GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
    ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
    FLUSH PRIVILEGES;
EOSQL

echo "🛑 Arrêt du serveur temporaire..."
mysqladmin -u root -p"${MYSQL_ROOT_PASSWORD}" shutdown
wait "$pid"

echo "✅ Initialisation terminée. Démarrage en mode production..."
exec mysqld --user=mysql --datadir=/home/ctravers/data/mariadb --bind-address=0.0.0.0