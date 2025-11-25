#!/bin/bash
set -e

echo "🚀 Configuration de WordPress..."

echo "⏳ Attente de la base de données..."
until mariadb -h"${WORDPRESS_DB_HOST}" -u"${WORDPRESS_DB_USER}" -p"${WORDPRESS_DB_PASSWORD}" -e "SELECT 1" >/dev/null 2>&1; do
    echo "⏳ MariaDB pas encore prêt..."
    sleep 3
done
echo "✅ Base de données accessible !"

if [ ! -f /usr/local/bin/wp ]; then
    echo "📥 Installation de WP-CLI..."
    curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
    chmod +x wp-cli.phar
    mv wp-cli.phar /usr/local/bin/wp
fi

cd /var/www/html

if [ ! -f wp-config.php ]; then
    echo "📝 Création de wp-config.php..."
    wp config create \
        --dbname="${WORDPRESS_DB_NAME}" \
        --dbuser="${WORDPRESS_DB_USER}" \
        --dbpass="${WORDPRESS_DB_PASSWORD}" \
        --dbhost="${WORDPRESS_DB_HOST}" \
        --allow-root
    echo "✅ wp-config.php créé !"
fi

if ! wp core is-installed --allow-root 2>/dev/null; then
    echo "📦 Installation de WordPress..."
    wp core install \
        --url="${WP_URL}" \
        --title="${WP_TITLE}" \
        --admin_user="${WP_ADMIN_USER}" \
        --admin_password="${WP_ADMIN_PASSWORD}" \
        --admin_email="${WP_ADMIN_EMAIL}" \
        --allow-root
    echo "✅ WordPress installé !"
    
    if [ -n "${WP_USER}" ]; then
        echo "👤 Création de l'utilisateur ${WP_USER}..."
        wp user create "${WP_USER}" "${WP_USER_EMAIL}" \
            --role=author \
            --user_pass="${WP_USER_PASSWORD}" \
            --allow-root
        echo "✅ Utilisateur créé !"
    fi
else
    echo "✅ WordPress déjà installé"
fi

chown -R www-data:www-data /var/www/html

echo "🚀 Démarrage de PHP-FPM..."

mkdir -p /var/log

exec php-fpm8.2 -F -R