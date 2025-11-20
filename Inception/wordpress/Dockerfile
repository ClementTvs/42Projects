FROM debian:12-slim

ENV DEBIAN_FRONTEND=noninteractive
ENV WORDPRESS_VERSION=6.7
ENV WORDPRESS_PATH=/var/www/html

# Installer PHP-FPM et extensions
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

# Télécharger WordPress
RUN mkdir -p "${WORDPRESS_PATH}" && \
    cd /tmp && \
    wget "https://wordpress.org/wordpress-${WORDPRESS_VERSION}.tar.gz" && \
    tar -xzf "wordpress-${WORDPRESS_VERSION}.tar.gz" && \
    cp -r wordpress/* "${WORDPRESS_PATH}/" && \
    rm -rf wordpress "wordpress-${WORDPRESS_VERSION}.tar.gz" && \
    chown -R www-data:www-data "${WORDPRESS_PATH}"

# ⭐ IMPORTANT : Copier la config PHP-FPM
COPY config/www.conf /etc/php/8.2/fpm/pool.d/www.conf

# Copier le script d'initialisation
COPY entrypoint.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/entrypoint.sh

EXPOSE 9000

CMD ["/usr/local/bin/entrypoint.sh"]