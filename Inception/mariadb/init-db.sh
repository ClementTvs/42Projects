#!/bin/bash
set -e

echo "🚀 Initialisation de MariaDB..."

if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "📦 Installation de la base système..."
    mysql_install_db --user=mysql --datadir=/var/lib/mysql
fi

echo "🔧 Démarrage temporaire pour configuration..."
mysqld --user=mysql --datadir=/var/lib/mysql --skip-networking &
pid="$!"

for i in {1..30}; do
    if mysqladmin ping --silent 2>/dev/null; then
        echo "✅ MariaDB prêt !"
        break
    fi
    echo "⏳ Attente de MariaDB... ($i/30)"
    sleep 1
done

echo "⚙️ Configuration de la base '${MYSQL_DATABASE}'..."
mysql -u root -p"${MYSQL_ROOT_PASSWORD}" <<-EOSQL
    CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
    CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
    GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
    FLUSH PRIVILEGES;
EOSQL


echo "🛑 Arrêt du serveur temporaire..."
mysqladmin -u root -p"${MYSQL_ROOT_PASSWORD}" shutdown
wait "$pid"

echo "✅ Initialisation terminée. Démarrage en mode production..."
exec mysqld --user=mysql --datadir=/var/lib/mysql --bind-address=0.0.0.0