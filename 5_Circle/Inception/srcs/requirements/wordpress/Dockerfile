FROM debian:bullseye

RUN apt-get update && apt-get install -y \
    apt-utils lsb-release ca-certificates apt-transport-https software-properties-common wget curl unzip mariadb-client gnupg dirmngr\
    && echo "deb https://packages.sury.org/php/ bullseye main" > /etc/apt/sources.list.d/sury-php.list \
    && wget -q -O- https://packages.sury.org/php/apt.gpg | gpg --dearmor > /etc/apt/trusted.gpg.d/sury-php.gpg \
    && apt-get update --allow-releaseinfo-change

RUN apt-get update && apt-get install -y \
    php8.0-fpm php8.0-mysql php8.0-mbstring php8.0-xml php8.0-curl php8.0-gd php8.0-zip \
    wget unzip curl mariadb-client \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /var/www/html

RUN wget https://wordpress.org/latest.tar.gz \
    && tar -xzf latest.tar.gz --strip-components=1 \
    && rm latest.tar.gz

COPY ./wp-config.php /var/www/html/wp-config.php

RUN chown -R www-data:www-data /var/www/html \
    && chmod -R 755 /var/www/html

COPY entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod +x /usr/local/bin/entrypoint.sh

EXPOSE 9000

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]
CMD ["php-fpm8.0", "-F"]