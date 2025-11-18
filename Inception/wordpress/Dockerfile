FROM debian:12-slim

# Variables d'environnement
ENV DEBIAN_FRONTEND=noninteractive
ENV WORDPRESS_VERSION=6.7
ENV WORDPRESS_PATH=/var/www/html

# Installer PHP-FPM et extensions nécessaires
RUN apt-get update && apt-get install -y \
    php-fpm \
    php-mysql \
    php-xml \
    php-gd \
    php-curl \
    php-zip \
    php-mbstring \
    php-intl \
    php-imagick \
    wget \
    tar \
    curl \
    less \
    unzip \
    mariadb-client \
    && rm -rf /var/lib/apt/lists/*

# Télécharger et installer WordPress
RUN set -eux; \
    echo "Téléchargement de WordPress version ${WORDPRESS_VERSION}..."; \
    mkdir -p "${WORDPRESS_PATH}"; \
    cd /tmp; \
    wget "https://wordpress.org/wordpress-${WORDPRESS_VERSION}.tar.gz"; \
    tar -xzf "wordpress-${WORDPRESS_VERSION}.tar.gz"; \
    cp -r wordpress/* "${WORDPRESS_PATH}/"; \
    rm -rf wordpress "wordpress-${WORDPRESS_VERSION}.tar.gz"; \
    chown -R www-data:www-data "${WORDPRESS_PATH}"

# Copier ta configuration FPM personnalisée
#COPY config/php-fpm.conf /etc/php/8.2/fpm/pool.d/www.conf

# Exposer le port du service PHP-FPM
EXPOSE 9000

# Lancer php-fpm au premier plan
CMD ["php-fpm8.2", "-F"]
