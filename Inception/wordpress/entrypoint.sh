#!/bin/bash
set -e

echo "🚀 Configuration de WordPress..."

# Attendre que MariaDB soit prêt
echo "⏳ Attente de la base de données..."
until mariadb -h"${WORDPRESS_DB_HOST}" -u"${WORDPRESS_DB_USER}" -p"${WORDPRESS_DB_PASSWORD}" -e "SELECT 1" >/dev/null 2>&1; do
    echo "⏳ MariaDB pas encore prêt..."
    sleep 3
done
echo "✅ Base de données accessible !"

# Créer wp-config.php si absent
if [ ! -f /var/www/html/wp-config.php ]; then
    echo "📝 Création de wp-config.php..."
    
    cat > /var/www/html/wp-config.php <<EOF
<?php
define('DB_NAME', '${WORDPRESS_DB_NAME}');
define('DB_USER', '${WORDPRESS_DB_USER}');
define('DB_PASSWORD', '${WORDPRESS_DB_PASSWORD}');
define('DB_HOST', '${WORDPRESS_DB_HOST}');
define('DB_CHARSET', 'utf8');
define('DB_COLLATE', '');

define('AUTH_KEY',         'put-unique-phrase-here');
define('SECURE_AUTH_KEY',  'put-unique-phrase-here');
define('LOGGED_IN_KEY',    'put-unique-phrase-here');
define('NONCE_KEY',        'put-unique-phrase-here');
define('AUTH_SALT',        'put-unique-phrase-here');
define('SECURE_AUTH_SALT', 'put-unique-phrase-here');
define('LOGGED_IN_SALT',   'put-unique-phrase-here');
define('NONCE_SALT',       'put-unique-phrase-here');

\$table_prefix = 'wp_';

define('WP_DEBUG', false);

if ( ! defined( 'ABSPATH' ) ) {
    define( 'ABSPATH', __DIR__ . '/' );
}

require_once ABSPATH . 'wp-settings.php';
EOF

    chown www-data:www-data /var/www/html/wp-config.php
    echo "✅ wp-config.php créé !"
else
    echo "✅ wp-config.php déjà présent"
fi

echo "🚀 Démarrage de PHP-FPM..."
exec php-fpm8.2 -F