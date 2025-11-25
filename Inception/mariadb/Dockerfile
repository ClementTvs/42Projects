FROM debian:12-slim

ENV MYSQL_ROOT_PASSWORD=rootpass \
    MYSQL_DATABASE=wordpress \
    MYSQL_USER=wp_user \
    MYSQL_PASSWORD=wp_pass

RUN apt-get update && \
    apt-get install -y mariadb-server && \
    rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/run/mysqld /home/ctravers/data/mariadb && \
    chown -R mysql:mysql /var/run/mysqld /home/ctravers/data/mariadb

COPY init-db.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/init-db.sh

EXPOSE 3306

VOLUME ["/home/ctravers/data/mariadb"]

CMD ["/usr/local/bin/init-db.sh"]